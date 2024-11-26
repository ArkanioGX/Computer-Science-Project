#include "Codility.h"
#include "random"
#include <string> 

void LaunchTest()
{
    int i;
    srand(time(NULL)*18064);
    std::cout << "=====- Codility Exercices -=====" << std::endl;
    std::cout << "===- Exerice 1 - 1 :" << std::endl;
    
    int input = std::rand() % 10000;
    std::cout << "Input : " << input << std::endl;
    int output = Exercice1_1(input);
    std::cout << "===" << std::endl;
    std::cout << "Output : " << output << std::endl;
    srand(rand());


    std::cout << "===- Exerice 2 - 1 :" << std::endl;
    
    std::vector<int> inputArray = {3, 8, 9, 7, 6};
    input = 3;

    std::cout << "Input Array : " << arrayToString(inputArray) << std::endl;
    std::cout << "Input : " << input << std::endl;
    std::vector<int> outputArray = Exercice2_1(inputArray,input);
    std::cout << "===" << std::endl;
    std::cout << "Output : " << arrayToString(outputArray) << std::endl;

    
}

std::string arrayToString(std::vector<int> &A){
    std::string str;
    str.append("[");
    for (int i = 0; i < A.size(); i++){
        str.append(std::to_string(A[i]));
        str.append(" ");
    }
    str.append("]");
    return str;
}

int Exercice1_1(int N)
{
    int zNumber = 0;
    int zNumberMax = 0;
    bool hasStarted = false;
    while (N > 0){
        if (N & 1){
            zNumberMax = zNumberMax < zNumber ? zNumber : zNumberMax;
            hasStarted = true;
            zNumber = 0;
        }
        else{
            if (hasStarted){
                zNumber++;
            }
        }
        N >>= 1;
    }
    return zNumberMax;
}

std::vector<int> Exercice2_1(std::vector<int> &A, int K)
{
    std::vector<int> rotatedVec(A);
    for (unsigned int i = 0; i < A.size(); i++){
        int newID = (i + K)%A.size();
        rotatedVec[newID] = A[i];
    }
    return rotatedVec;
}

int Exercice2_2(std::vector<int> &A)
{
    std::unordered_map<int, unsigned int> list;
    for (unsigned int i = 0; i < A.size(); i++){
        list[A[i]] = list[A[i]] + 1;
    }
    for (auto& i: list){
        if (i.second % 2 == 1){
            return i.first;
        }
    }
    return 0;
}

int Exercice3_1(int X, int Y, int D)
{
    double dist = Y - X;
    return std::ceil(dist/D);
}

double recursiveAdd(int n)
{
    return n > 1 ? n + recursiveAdd(n-1) : n;
}

int Exercice3_2(std::vector<int> &A)
{
    double n = 0;
    for (unsigned int i = 0; i < A.size(); i++){
        n += A[i];
    }
    return recursiveAdd(A.size()+1) - n;
}

int Exercice3_3(std::vector<int> &A)
{
    int minDiff = std::numeric_limits<int>::max();
    int sum1 = 0;
    int sum2 = 0;
    for (unsigned int i = 0; i < A.size(); i++){
        sum1 += A[i];
    }
    for (unsigned int i = 0; i < A.size()-1; i++){
        sum1 -= A[i];
        sum2 += A[i];

        int diff = std::abs(sum2-sum1);
        minDiff = minDiff > diff ? diff : minDiff;
    }
    return minDiff;
}
