#include "Codility.h"

void LaunchTest()
{
    int i;
    std::cout << "Hello";
    std::cin >> i;
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
