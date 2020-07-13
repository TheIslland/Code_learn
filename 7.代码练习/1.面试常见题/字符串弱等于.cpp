/************************************************************
    File Name : 字符串弱等于.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-07-12 星期天 11:51:13
************************************************************/
bool weak_equivalent(string &str1, string &str2) {
    if (!str1.compare(str2)) return true;
    if ((str1.size() & 1) || (str2.size() & 1)) return false;
    else {
        int mid = str1.size() / 2;
        string str[4] = {str1.substr(0, mid), str1.substr(mid, mid), str2.substr(0, mid), str2.substr(mid, mid)};
        return (weak_equivalent(str[0], str[2]) && weak_equivalent(str[1], str[3])) || (weak_equivalent(str[0], str[3]) && weak_equivalent(str[1], str[2]));
    }    
}