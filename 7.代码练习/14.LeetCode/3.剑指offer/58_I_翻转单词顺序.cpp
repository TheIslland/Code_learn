/************************************************************
    File Name : 58_I_翻转单词顺序.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-17 星期五 19:35:22
************************************************************/
//流输入+栈
class Solution {
public:
    string reverseWords(string s) {
        istringstream input(s);
        string ret, temp;
        stack<string> arr;
        while (input >> temp) {
            arr.push(temp);
            arr.push(" ");
        }
        if (!arr.empty()) arr.pop();
        while (arr.size()) {
            ret += arr.top();
            arr.pop();
        }
        return ret;
    }
};

//双指针
class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())return s;
        int len = 0;
        string ans = "";
        for(int m = s.size()-1; m >=0; m--)
        {
            if(s[m]==' '&&len!=0)
            {
                ans += s.substr(m+1,len)+ " ";len = 0; continue;
            }
            if(s[m]!= ' ')len++;
        }
        if(len !=0) ans += s.substr(0,len) + " ";
        if(ans.size()>0)ans.erase(ans.size()-1,1);
        return ans;

    }
};
