/************************************************************
    File Name : 13_机器人的运动范围.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-14 星期二 19:03:26
************************************************************/
class Solution {
public:
    bool judg(int x, int y, int k) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        while (y) {
            sum += y % 10;
            y /= 10;
        }
        return sum <= k;
    }
    int flag[105][105] = {0};
    int movingCount(int m, int n, int k) {
        return dfs(0, 0, m, n, k);
    }
    int dfs(int x, int y, int m, int n, int k) {
        if (x < 0 || x >= m || y < 0 || y >= n || judg(x, y, k) == false || flag[x][y] == 1) return 0;
        flag[x][y] = 1;
        return dfs(x + 1, y, m, n, k) + dfs(x, y + 1, m, n, k) + 1;
    }
};

//广搜
class Solution {
public:
    bool judg(int x, int y, int k) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        while (y) {
            sum += y % 10;
            y /= 10;
        }
        return sum <= k;
    }
    int dir[2][2] = {{1, 0},{0, 1}};
    int movingCount(int m, int n, int k) {
        int visited[105][105] = {0};
        queue<pair<int, int>> q;
        q.push({0, 0});
        int res = 0;
        visited[0][0] = 1;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int x = front.first;
            int y = front.second;
            res += 1;
            for (int i = 0; i < 2; i++) {
                int new_x = x + dir[i][0];
                int new_y = y + dir[i][1];
                if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n 
                    || visited[new_x][new_y] == 1 ||
                    judg(new_x, new_y, k) == false) {
                    continue;
                }
                q.push({new_x, new_y});
                visited[new_x][new_y] = 1;
            }
        }
        return res;
    }
};