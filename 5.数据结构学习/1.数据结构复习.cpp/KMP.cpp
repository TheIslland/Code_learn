/************************************************************
    File Name : KMP.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-23 星期四 09:07:49
************************************************************/
#include <ctime>
#include <iostream>

using namespace std;

int kmp(string str, string pat) {
    int *next = (int *)malloc(sizeof(int) * pat.length());
    for (int i = 0, j = -1; pat[i]; i++) {
        while (j != -1 && pat[j + 1] != pat[i]) j = next[j];
        if (pat[j + 1] == pat[i]) j += 1;
        next[i] = j;
    }
    for (int i = 0, j = -1; str[i]; i++) {
        while (j != -1 && pat[j + 1] != str[i]) j = next[j];
        if (pat[j + 1] == str[i]) j += 1;
        if (pat[j + 1] == 0) return i - pat.length() + 1;
    }
    return -1;
}
void output(string str, int ind) {
    if (ind < 0) {
        cout << "Not Foune" << endl;
    }
    cout << "pattern first start = ";
    for (int i = ind; i < str.length(); i++) {
        cout << str[i];
    }
    cout << endl;
}
int main() {
    string str, pat;
    cin >> str >> pat;
    int ind = kmp(str, pat);
    output(str, ind);

    return 0;
}