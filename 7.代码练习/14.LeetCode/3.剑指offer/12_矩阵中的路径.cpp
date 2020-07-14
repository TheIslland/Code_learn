/************************************************************
    File Name : 12_矩阵中的路径.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-14 星期二 18:27:52
************************************************************/
class Solution {
public:
    int dir[4][2] = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};
    int flag[205][205] = {0};
    int len1, len2;
    string str;
    bool dfs(vector<vector<char>>& num, int x, int y, int n) {
        if (n == str.length()) return true;
        //if () return false; 
        flag[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (xx < 0 || xx >= len1 || yy < 0 || yy >= len2 || num[xx][yy] != str[n] || flag[xx][yy] == 1) continue;
            if (dfs(num, xx, yy, n + 1)) return true;
        }
        flag[x][y] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        memset(flag, 0, 205 * 205 * sizeof(int));
        len1 = board.size(), len2 = board[0].size();
        if (word.length() > len1 * len2) return false;
        str = word;
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, i, j, 1)) return true; 
                    memset(flag, 0, 205 * 205 * sizeof(int));
                }
            }
        }
        return false;
    }
};