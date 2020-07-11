/*************************************************************************
        > File Name: 167字符串操作2.cpp
        > Author: TheIslland
        > Mail: voidland@163.com, 861436930@qq.com
        > Created Time: Mon Nov  4 16:45:12 2019
 ************************************************************************/

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    char a[10005], b[10005];
    char ans[20005];
    int n;
    scanf("%s", &a);
    scanf("%d", &n);
    scanf("%s", &b);
    int len = strlen(a), temp = 0;
    printf("%d\n", len);
    for (int i = 0; i <= len - 1; i++) {
        temp++;
        if (a[i] == 'a') {
            printf("%d\n", temp);
            break;
        }
    }
    strncpy(ans, a, n - 1);
    strcat(ans, b);
    strncpy(ans + n + strlen(b) - 1, a + n - 1, len - n + 1);
    printf("%s\n", ans);
}

/*int main() {
    string a, b;
    int n;
    cin >> a >> n >> b;
    int len1 = a.length();
    cout << len1 << endl;
    int ans = 0;
    for (int i = 0; i <= len1 - 1; i++) {
        ans++;
        if (a[i] == 'a') {
            cout << ans << endl;
            break;
        }
    }
    a.insert(n - 1, b);
    cout << a << endl;
    return 0;
}*/
       