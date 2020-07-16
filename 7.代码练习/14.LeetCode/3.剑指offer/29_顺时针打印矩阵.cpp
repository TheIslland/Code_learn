/************************************************************
    File Name : 29_顺时针打印矩阵.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-16 星期四 09:15:24
************************************************************/
//第一版：完全模拟
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return vector<int> {};
        vector<int> ret;
        int i = 0, j = 0, l = 0, r = matrix[0].size() - 1, up = 0, down = matrix.size() - 1, flag = matrix.size() * matrix[0].size();
        while (ret.size() < flag) {
            for (j = l; j <= r; j++) ret.push_back(matrix[i][j]);
            j--;
            up++;
            if (up > down) break;
            for (i = up; i <= down; i++) ret.push_back(matrix[i][j]);
            i--;
            r--;
            if (r < l) break;
            for (j = r; j >= l; j--) ret.push_back(matrix[i][j]);
            j++;
            down--;
            if (down < up) break;
            for (i = down; i >= up; i--) ret.push_back(matrix[i][j]);
            i++;
            l++;
            if (l > r) break;
            /*for (int k =0 ; k < ret.size(); k++) cout << ret[k] << ",";
            cout << endl;*/
        }
        return ret;
    }
};

//代码精简
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return vector<int> {};
        vector<int> ret(matrix[0].size() * matrix.size());
        int l = 0, r = matrix[0].size() - 1, up = 0, down = matrix.size() - 1, x = 0;
        while (true) {
            for (int j = l; j <= r; j++) ret[x++] = (matrix[up][j]);
            if (++up > down) break;
            for (int i = up; i <= down; i++) ret[x++] = (matrix[i][r]);
            if (--r < l) break;
            for (int j = r; j >= l; j--) ret[x++] = (matrix[down][j]);
            if (--down < up) break;
            for (int i = down; i >= up; i--) ret[x++] = (matrix[i][l]);
            if (++l > r) break;
            /*for (int k =0 ; k < ret.size(); k++) cout << ret[k] << ",";
            cout << endl;*/
        }
        return ret;
    }
};