/************************************************************
    File Name : 杨辉三角.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-13 星期一 14:58:35
************************************************************/
long long PascalTriangle(int row, int column) {
    long long num[100][100] = {0};
    if (row <= 1) return row;
    num[1][1] = 1;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= i; j++) {
            num[i + 1][j] += num[i][j];
            num[i + 1][j + 1] += num[i][j];
        }
    }
    return num[row][column];
}