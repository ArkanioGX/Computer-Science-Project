
#include "City Travel.h"
#include <limits>

#define inf std::numeric_limits<int>::max();



Path* getMostValuablePath(City* cityStart, std::vector<City*> unvisitedCity);

std::vector<City*> City::list = {};

void findPath()
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



    std::vector<pathFindingData*> cityRemaining;
    std::vector<Path*> pathFound;
    City* start = cityA;
    City* check = start;

{
    std::vector<City*> cityList = City::list; 
    for (int i = 0; i < cityList.size(); i++){
        if (cityList[i] != start){
            pathFindingData* pathData = new pathFindingData();
            pathData->dest = cityList[i];
            pathData->currDist = inf;
            cityRemaining.push_back(pathData);
        }
    }

    std::cout << "test";
}
    

    //Pathfinding Begin

    while (cityRemaining.size() != 0) {
        
    }
}

