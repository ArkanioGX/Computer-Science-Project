#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <vector>
#include <iostream>

class Codility{
    public:
        static void LaunchTest();
    private:
        static int Exercice1_1(int N);

        static std::vector<int> Exercice2_1(std::vector<int> &A, int K);

        static int Exercice2_2(std::vector<int> &A);

        static int Exercice3_1(int X, int Y, int D);

        static double recursiveAdd(int n);
        static int Exercice3_2(std::vector<int> &A);

        static int Exercice3_3(std::vector<int> &A);
};