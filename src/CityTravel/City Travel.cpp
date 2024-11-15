
#include <iostream>
#include <vector>
#include <string>

class City {
public:
    City() :name(""), pathsList(std::vector<class Path*>()) {};
    City(std::string cname) : name(cname), pathsList(std::vector<class Path*>()) { std::cout << "City " << name << " created !!" << std::endl; };

    void addPath(class Path* p) { if (std::find(pathsList.begin(), pathsList.end(),p) == pathsList.end()) pathsList.push_back(p); }

    std::string getName() { return name; }
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

Path* getMostValuablePath(City* cityStart, std::vector<City*> unvisitedCity);

int main()
{

    //City Creations
    City* cityA = new City("A");
    City* cityB = new City("B");
    City* cityC = new City("C");
    City* cityD = new City("D");
    City* cityE = new City("E");

    //A Paths
    Path* path = new Path(cityA, cityB, 2);
    path = new Path(cityA, cityC, 2);

    //B Paths
    path = new Path(cityB, cityC, 3);
    path = new Path(cityB, cityD, 3);
    path = new Path(cityB, cityE, 1);

    //C Paths
    path = new Path(cityC, cityD, 1);
    path = new Path(cityC, cityE, 3);

    //D Paths
    path = new Path(cityD, cityE, 3);

    std::vector<City*> cityRemaining;
    std::vector<Path*> pathFound;
    City* start = cityA;
    City* check = start;
    while (cityRemaining.size() != 0) {
        Path* p = getMostValuablePath(check, cityRemaining);
        check = p->getOtherCity(check);
        cityRemaining.erase(std::find(cityRemaining.begin(), cityRemaining.end(), check));
    }
}

Path* getMostValuablePath(City* cityStart, std::vector<City*> unvisitedCity) {
    return nullptr;
}
