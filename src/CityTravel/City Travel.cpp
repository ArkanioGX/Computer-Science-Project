
#include "City Travel.h"
#include <limits>

#define inf std::numeric_limits<int>::max();

std::vector<City*> cityExplored; 
std::vector<pathFindingData*> pathAvailable; 



Path* getMostValuablePath(City* cityStart, std::vector<City*> unvisitedCity);

std::vector<City*> City::list = {};

void findPath()
{
    std::cout << "=====- Travelling Merchant -=====" << std::endl;
    std::cout << "===- City Creation :" << std::endl << std::endl;
    //City Creations
    City* cityA = new City("A");
    City* cityB = new City("B");
    City* cityC = new City("C");
    City* cityD = new City("D");
    City* cityE = new City("E");

    std::cout << std::endl << "===- Paths Creation :" << std::endl << std::endl;

    //A Paths
    Path* path = new Path(cityA, cityB, 2);
    path = new Path(cityA, cityC, 2);

    //B Paths
    path = new Path(cityB, cityC, 3);
    path = new Path(cityB, cityD, 3);
    path = new Path(cityB, cityE, 1);

    //D Paths
    path = new Path(cityD, cityE, 3);

    //C Paths
    path = new Path(cityC, cityD, 1);
    path = new Path(cityC, cityE, 3);

    



    std::vector<Path*> pathFound;
    City* start = cityA;
    City* currentCity = start;

    std::vector<City*> cityList = City::list; 

    
    cityExplored.push_back(currentCity);

    //Pathfinding Begin

    while (cityExplored.size() != cityList.size()) {
        pathAvailable.clear();
        findSubPath(currentCity);
        pathFindingData* shortestPath = findLowestDistancePath(pathAvailable);

        cityExplored.push_back(shortestPath->dest);
        

        for (int i = 0; i < shortestPath->pathUsed.size(); i++){
            pathFound.push_back(shortestPath->pathUsed[i]);
        }

        currentCity = shortestPath->dest;
    }

    //Remove the first so it can find his way back to start
    cityExplored.erase(cityExplored.begin());
    pathAvailable.clear();
    findSubPath(currentCity);
    pathFindingData* shortestPath = findLowestDistancePath(pathAvailable);

    cityExplored.push_back(shortestPath->dest);

    for (int i = 0; i < shortestPath->pathUsed.size(); i++){
        pathFound.push_back(shortestPath->pathUsed[i]);
    }
    std::cout << std::endl << "===- Paths Found :" << std::endl << std::endl;
    currentCity = start;
    float pathDistance = 0;
    for (int i = 0; i < pathFound.size(); i++){
        std::cout << currentCity->getName() << " ---> " << pathFound[i]->getOtherCity(currentCity)->getName() << "( distance : " << pathDistance << " (+" << pathFound[i]->getDistance() << "))" << std::endl;
        pathDistance += pathFound[i]->getDistance();
        currentCity = pathFound[i]->getOtherCity(currentCity);
    }
    std::cout << std::endl << "===- Total Distance = " << pathDistance << std::endl;
}

void findSubPath(City* currentCity, pathFindingData lastPfd )
{   
    std::vector<City*>::iterator cityExploredIt = std::find(cityExplored.begin(),cityExplored.end(),currentCity);
    if (cityExploredIt == cityExplored.end())
    {
        std::vector<pathFindingData*>::iterator pathFoundIt = otherPathLeadingToThisCity(lastPfd);
        //Check if a path is already leading to this city
        if (pathFoundIt != pathAvailable.end()){
            //Compare the distance of paths to determine which one will be used
            if (lastPfd.currDist > (*pathFoundIt)->currDist){
                return;
            }
            pathAvailable.erase(pathFoundIt);
        }
        pathFindingData* newPath = new pathFindingData(lastPfd);
        pathAvailable.push_back(newPath);
        return;
    }
    else{
        //Explored City Continue
        std::vector<Path*> cityPaths = currentCity->getPaths();
        for (int i = 0; i < cityPaths.size(); i++){
            //Return if its the path ur coming from
            if (cityPaths[i]->getOtherCity(currentCity) == lastPfd.getLastExploredCity()){
                return;
            }
            //Return if this city is already explored in the current path
            if (lastPfd.hasExploredThisCity(cityPaths[i]->getOtherCity(currentCity))){
                return;
            }
            pathFindingData newPfd = lastPfd;
            newPfd.addToData(currentCity,cityPaths[i]);
            findSubPath(cityPaths[i]->getOtherCity(currentCity),newPfd);
        }
    }
}

pathFindingData* findLowestDistancePath(std::vector<pathFindingData *> pathList)
{
    float minDist = inf;
    pathFindingData* minDistPath = nullptr;
    for (int i = 0; i < pathList.size(); i++){
        if (pathList[i]->currDist < minDist){
            minDist = pathList[i]->currDist;
            minDistPath = pathList[i];
        }
    }
    return minDistPath;
}

std::vector<pathFindingData *>::iterator otherPathLeadingToThisCity(pathFindingData pfd)
{
    std::vector<pathFindingData*>::iterator it = std::find(pathAvailable.begin(),pathAvailable.end(),&pfd) ;
    return it;
}
