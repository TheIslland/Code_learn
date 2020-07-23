/************************************************************
    File Name : shift_and.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-23 星期四 10:35:41
************************************************************/
#include <ctime>
#include <bitset>
#include <iostream>

using namespace std;

//模式串为短串时采用
int shift_and(string str, string t) {
    int code[256] = {0};
    for (int i = 0; t[i]; i++) {
        code[t[i]] |= (1 << i);
    }
    int p = 0, len = t.length();
    for (int i = 0; str[i]; i++) {
        p = (p << 1 | 1) & code[str[i]];
        if (p & (1 << (len - 1))) return i - len + 1;
    }
    return -1;
}
/*模式串为长串时采用
    int shift_and(string str, string t) {
    bitset<256> code[256] = {0};
    for (int i = 0; t[i]; i++) {
        code[t[i]] |= (1 << i);
    }
    int len = t.length();
    bitset<256> p("0");
    bitset<256> x("1");
    bitset<256> flag(1 << (len - 1)); //超过unsigned int范围需要先计算存入字符串后再初始化
    for (int i = 0; str[i]; i++) {
        p = (p << 1 | x) & code[str[i]];
        if ((p & flag) == flag) return i - len + 1;
    }
    return -1;
}
*/
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
    int ind = shift_and(str, pat);
    output(str, ind);

    return 0;
}