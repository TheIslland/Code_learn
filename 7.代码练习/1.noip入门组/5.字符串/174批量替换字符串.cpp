/*************************************************************************
        > File Name: 174批量替换字符串.cpp
        > Author: TheIslland
        > Mail: voidland@163.com, 861436930@qq.com
        > Created Time: Mon Nov  4 23:45:17 2019
 ************************************************************************/

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    while (str.find(" ", 0) != -1) {
        int pos = str.find(" ", 0);
        str.replace(pos, 1, "%20");
    }
    cout << str << endl;
}

/*
char str[300005] = {0};
char bstr[300005];//转换缓冲区

int main() {
    int n;
        char sub[] = " ";
        char object[] = "%20";
                scanf("%[^\n]s", str);
        //str[i] = strrpc(&str[i], sub, object);
                memset(bstr, 0, sizeof(bstr));

                for (int i = 0; i < strlen(str); i++) {
                        if (!strncmp(str + i, sub, strlen(sub)))
{//查找目标字符串 strcat(bstr, object); i += strlen(sub) - 1;
                        }
                        else {
                                strncat(bstr, str + i, 1);//保存一字节进缓冲区
                        }
                }
                strcpy(str, bstr);
    cout << str << endl;
    return 0;
}*/
