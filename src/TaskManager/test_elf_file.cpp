#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>

const int M = 301;
const int COL = 3;
const int N = COL + 2;

int find_max(int Result[][N], int i) {
    int mInf = -10000;
    int rez = 0;
    if(i < 0) {
        rez = mInf;
    } else {
        rez = Result[i][1];
    }

    return rez;
}


int main() {
    int MC[COL][2];

    std::ifstream file("data.txt");
    for (int i = 0; i < COL; i++) {
        for (int j = 0; j < 2; j++) {
            file >> MC[i][j];
            std::cout << MC[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int Result[M][N];

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if (j == 0) {
                Result[i][j] = i;
            } else {
                Result[i][j] = 0;
            }
        }
    }

    int Max = -10000, iTemp = 0, temp = 0;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < COL; j++) {
            temp = find_max(Result, i - MC[j][0]) + MC[j][1];
            if (temp >= Max) {
                Max = temp;
                iTemp = j;
            }
        }
        if (Max <= 0) {
            Result[i][1] = 0;
        } else {
            Result[i][1] = Max;
            for(int j = 0; j < COL; j++) {
                if (j == iTemp) {
                    Result[i][j + 2] = Result[i - MC[j][0]][j + 2] + 1;
                } else if (i - MC[j][0] < 0) {
                    Result[i][j + 2] = 0;
                } else {
                    Result[i][j + 2] = Result[i - MC[iTemp][0]][j + 2];
                }
            }
        }

        Max = -10000;
        iTemp = 0;
    }

    std::cout << "Weight:\tCost:\n";
    for(int i = 0; i < COL; i++) {
        for(int j = 0; j < 2; j++) {
            std::cout << MC[i][j] <<"\t";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Final Cost: "<< "\t1" << "\t2" << "\t3" << std::endl;
    for(int i = M-1; i < M; i++) {
        for(int j = 1; j < N; j++) {
            if (j == 1) {
                std::cout << Result[i][j] << "\t\t";
            } else {
                std::cout << Result[i][j] << "\t";

            }
        }
        std::cout << std::endl;
    }
    int res_arr = (Result[M - 1][2]  * MC[0][0] + Result[M - 1][3] * MC[1][0] + Result[M - 1][4] * MC[2][0]);
    std::cout << "Resault Weight: " << res_arr << "\t" << std::endl;

    return 0;
}