/************************************************************
    File Name : 38_字符串的排列.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-17 星期五 09:18:44
************************************************************/
//由题意可知采取剪枝全排列即可
class Solution {
public:
    void dfs(vector<string> &ret, string &str, int pos) {
        if (pos == str.length() - 1) {
            ret.push_back(str);
            return ;
        }
        for (int i = pos; i < str.length(); i++) {
            if (cut_tree(str, pos, i)) continue;
            swap(str[i], str[pos]);
            dfs(ret, str, pos + 1);
            swap(str[i], str[pos]);
        }
        return ;
    }
    //简直函数用于判断前缀部分是否有与当前置换值重复元素，有则剪枝不去递归，没有交换首部递归
    bool cut_tree(string &str, int pos, int x) {
        for (int i = pos; i < x; i++) if (str[i] == str[x]) return true;
        return false;
    }
    vector<string> permutation(string s) {
        vector<string> ret;
        dfs(ret, s, 0);
        return ret;
    }
};