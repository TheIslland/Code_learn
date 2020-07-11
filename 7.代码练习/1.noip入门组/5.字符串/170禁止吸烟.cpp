/*************************************************************************
        > File Name: 170禁止吸烟.cpp
        > Author: TheIslland
        > Mail: voidland@163.com, 861436930@qq.com
        > Created Time: Mon Nov  4 22:16:56 2019
 ************************************************************************/

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;
char ans[1000][1000] = {0};

int main() {
    int n;
    string str[1000];
    cin >> n;
    string target = "Ban_smoking";
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        while (str[i].find("Ban_smoking") != -1) {
            int pos = str[i].find("Ban_smoking");
            str[i].replace(pos, 11, "No_smoking");
        }
    }
    for (int i = 0; i < n; i++) {
        cout << str[i] << endl;
    }
    return 0;
}

/*
int main() {
    int n;
    scanf("%d", &n);
    char a[] = {"No_smoking"};
    char b[] = {"Ban_smoking"};
    int len2 = strlen(b);
    for (int i = 0; i < n; i++) {
        char str[1000];
        scanf("%s", &str);
        int len1 = strlen(str);
        for (int j = 0; j < len1; j++) {
            if (!strncmp(str + j, b, len2)) {
                strcat(ans[i], a);
                j += len2 - 1;
            } else {
                strncat(ans[i], str + j, 1);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", ans[i]);
    }
    return 0;
}
*/
/*int main() {
    int n;
    cin >> n;
        char sub[] = "Ban_smoking";
        char object[] = "No_smoking";
    for (int i = 0; i < n; i++) {
                char str[1000];
                cin >> str;
                //str[i] = strrpc(&str[i], sub, object);
                char bstr[strlen(str)];//转换缓冲区
                memset(bstr, 0, sizeof(bstr));

                for (int i = 0; i < strlen(str); i++) {
                        if (!strncmp(str + i, sub, strlen(sub)))
{//查找目标字符串 strcat(bstr, object); i += strlen(sub) - 1;
                        }
                        else {
                                strncat(bstr, str + i, 1);//保存一字节进缓冲区
                        }
                }
                strcpy(ans[i], bstr);

    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
*/
