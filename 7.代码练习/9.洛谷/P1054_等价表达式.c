/*************************************************************************
	> File Name: P1054_等价表达式.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月21日 星期日 16时58分42秒
 ************************************************************************/
#include <stdio.h>
#include  <stdlib.h>
#include <string.h>
#include <math.h>
#define INF 0X3f3f3f3f
#define MD 100000007
#define ll long long
ll calc(char *str, int l, int r, int a_value) {
    int pos = -1, temp_prior = 0, prior = INF - 1;
    for (int i = l; i <= r; i++) {
        int cur_prior = INF;
        switch (str[i]) {
            //case 'a': str[i] = a_value + '0'; break;
            case '(': temp_prior += 100; break;
            case ')': temp_prior -= 100; break;
            case '+': cur_prior = temp_prior + 1; break;
            case '-': cur_prior = temp_prior + 1; break;
            case '*': cur_prior = temp_prior + 2;break;
            case '/': cur_prior = temp_prior + 2; break;
            case '^': cur_prior = temp_prior + 3; break;
        }
        if (cur_prior <= prior) {
            prior = cur_prior;
            pos = i;
        }
    }
        if (pos == -1) {
            int num = 0;
            for (int i = l ; i <= r; i++) {
                if (str[i] == 'a') return a_value;
                if ( str[i] < '0' || str[i] > '9') continue;
                num = (num * 10 + str[i] - '0') % MD;
            }
            return num;
        } else {
            ll a = calc(str, l, pos -1, a_value);
            ll b = calc(str, pos + 1, r, a_value);
            switch (str[pos]) {
                case '+':return (a + b) % MD;
                case '-': return (a - b) % MD;
                case '*': return a * b % MD;
                case '/':return a / b % MD;
                case '^': {
                    ll ans = 1;
                    for (int i = 0; i < b; i++) {
                        ans = ans * a % MD;
                    }
                    return ans % MD;
                }
            }
        }
    return 0;
}

int main() {
    int n;
    char str[1000000];
    char ch[1000000];
    scanf("%[^\n]s", ch),getchar();
    scanf("%d", &n),getchar();
    ll x = calc(ch, 0, strlen(ch) - 1, 3);
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%[^\n]s",str);
        ll h = calc(str, 0, strlen(str) - 1, 3);
        //printf("[%lld =  %lld]\n", h, x);
        if (h == x) {
            printf("%c", 'A' + i);
        }
        memset(str, 0, sizeof(str));
        }   
    return 0;
}
