/************************************************************
    File Name : 马踏过河卒.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-13 星期一 14:41:34
************************************************************/

int x[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int y[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

long long numberOfPaths(int BX, int BY, int CX, int CY) {
    long long num[25][25] = {0};
    num[0][0] = 1;
    for (int i = 0; i < 8; i++) {
        num[CX + x[i]][CY + y[i]] = -1;
    }
    num[CX][CY] = -1;
    for (int i = 0; i <= BX; i++) {
        for (int j = 0; j <= BY; j++) {
            if (num[i][j] == -1) continue;
            if (num[i + 1][j] != -1) num[i + 1][j] += num[i][j];
            if (num[i][j + 1] != -1) num[i][j + 1] += num[i][j];
        }
    }
    return num[BX][BY] < 0 ? 0 : num[BX][BY];
}