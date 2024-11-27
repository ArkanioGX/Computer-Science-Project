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

    City* dest;
    float currDist;

    bool operator==(const pathFindingData& pfd) {
        return pfd.dest == dest;
    }
};

void findPath();