/*
        DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
                    Version 2, December 2004 

 Copyright (C) 2004 Sam Hocevar <sam@hocevar.net> 

 Everyone is permitted to copy and distribute verbatim or modified 
 copies of this license document, and changing it is allowed as long 
 as the name is changed. 

            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION 

  0. You just DO WHAT THE FUCK YOU WANT TO.
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// [WARNING] 该程序未完全 AC！

// 该函数用于将一个字符串的所有大写字母转为小写字母
string &toslower(string &n){
    for(auto &i : n) i = tolower(i);
    return n;
}

int main(){
    string searching;
    getline(cin, searching);
    toslower(searching);
    // 这里其实要考虑到三种情况，搜索的单词可能在开头、中间或末尾，所以空格需要按需使用
    string searchingBegin = searching + ' '; // 开头
    string searchingEnd = ' ' + searching; // 结尾
    searching = ' ' + searching + ' '; // 中间

    string in;
    getline(cin, in);
    toslower(in);

    if(in.find(searching) == string::npos) cout << - 1 << flush;
    else{
        // 为了能输出第一个欲搜索文本所在位置，所以这里先手动搜索一次开头
        int count = 1; // 先初始化为已找到一次
        int pos = in.find(searchingBegin) == string::npos ? 0 : in.find(searchingBegin); // 以开头专用单词搜寻一次
        int firstPos = pos; // 记录第一个搜寻到的单词位置

        // 搜索中间
        for(
            int n = in.find(searching, pos); // 搜寻一次
            n != string::npos; // 当找不到后退出
            ++count, // 递增统计
            pos = n + searching.size(), // 移动下标到刚刚找到的文本后面
            n = in.find(searching, pos) // 继续重复寻找
        );

        // 搜索末尾
        if(in.substr(in.size() - searchingEnd.size()) == searchingEnd) ++count;
        // 考虑位于最后的词即为第一个匹配词的极端情况
        if(in.find(searching, 0) == string::npos) firstPos = in.size() - searchingEnd.size();

        cout << count << " " << firstPos << flush;
    }

    return 0;
}