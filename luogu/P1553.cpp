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
#include <algorithm>
#include <string>

using namespace std;

void removeFrontZero(string &str){
    auto pos = str.find_first_not_of('0');
    if(pos == string::npos){
        // 判断是否全为 0
        bool isFullOfZero = true;
        for(auto &i : str) if(i != '0') isFullOfZero = false;
        if(isFullOfZero) str = "0";
    }else{
        str = str.substr(pos);
    }
}

int main(){
    string in;
    cin >> in;

    // 判断数字类型
    if(in.find('.') != string::npos){
        // 为小数类型
        string left = in.substr(0, in.find('.'));
        string right = in.substr(in.find('.') + 1);
        reverse(left.begin(), left.end());
        removeFrontZero(left);
        removeFrontZero(right);
        reverse(right.begin(), right.end());
        cout << left << "." << right << flush;
    }else if(in.find('%') != string::npos){
        // 为百分比类型
        string num = in.substr(0, in.size() - 1);
        reverse(num.begin(), num.end());
        removeFrontZero(num);
        cout << num << "%" << flush;
    }else if(in.find('/') != string::npos){
        // 为分数类型
        string left = in.substr(0, in.find('/'));
        string right = in.substr(in.find('/') + 1);
        reverse(left.begin(), left.end());
        removeFrontZero(left);
        removeFrontZero(right);
        reverse(right.begin(), right.end());
        removeFrontZero(right);
        cout << left << "/" << right << flush;
    }else{
        // 为整数
        reverse(in.begin(), in.end());
        removeFrontZero(in);
        cout << in << flush;
    }

    return 0;
}