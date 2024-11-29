#include <iostream>
#include <vector>
#include <string>



class City {
public:
    City() :name(""), pathsList(std::vector<class Path*>()) {};
    City(std::string cname) : name(cname), pathsList(std::vector<class Path*>()) { 
        std::cout << "City " << name << " created !!" << std::endl;
        list.push_back(this);
         };

    void addPath(class Path* p) { if (std::find(pathsList.begin(), pathsList.end(),p) == pathsList.end()) pathsList.push_back(p); }
    std::vector<class Path*> getPaths() { return pathsList;}

    std::string getName() { return name; }

    static std::vector<City*> list;

    bool operator==(const City& c) {
        return name.compare(c.name) == 0;
    }

private:
    std::string name;
    std::vector<class Path*> pathsList;

    
};

class Path {
public:
    Path() = delete;
    Path(City* c1, City* c2, float dist) : city1(c1), city2(c2), distance(dist) {
        c1->addPath(this);
        c2->addPath(this);

        std::cout << "Path between " << city1->getName() << " and " << city2->getName() << " created !! " << std::endl;
    };

    City* getOtherCity(City* c1) {
        return city1 != c1 ? city1 : city2;
    }

    float getDistance() {
        return distance;
    }
private:
    City* city1;
    City* city2;
    float distance;
};

struct pathFindingData {

    std::vector<Path*> pathUsed;
    bool bIsUnexploredCity = false;
    City* dest;
    float currDist = 0;

    bool operator==(const pathFindingData& pfd) {

        return pfd.dest == dest;
    }

    void addToData(City* currentCity, Path* newPath){
        dest = newPath->getOtherCity(currentCity);
        pathUsed.push_back(newPath);
        currDist += newPath->getDistance();
    }

    City* getLastExploredCity (){
        if (pathUsed.size() == 0) {return nullptr;}
        return pathUsed.back()->getOtherCity(dest);
    }

    bool hasExploredThisCity(City* cityToCheck){
        City* c = cityToCheck;
        for (int i = pathUsed.size()-1; i >= 0; i--){
            c = pathUsed[i]->getOtherCity(c);
            if (cityToCheck == c){
                return true;
            }
        }
        return false;
    }

};

void findPath();

void findSubPath(City* currentCity, pathFindingData lastPfd= pathFindingData());

pathFindingData* findLowestDistancePath(std::vector<pathFindingData *> pathList);

std::vector<pathFindingData*>::iterator otherPathLeadingToThisCity(pathFindingData pfd);