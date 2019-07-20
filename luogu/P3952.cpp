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
#include <vector>
#include <string>
#include <sstream>
#include <cctype>

// #define DEBUG
#include "../big_baby.h"

// 暂未 AC

using namespace std;

struct line {
    string flag, name, initVal, roundToVal;
    line(string f) : flag(f) { }
    line(string f, string n, string i, string r) : flag(f), name(n), initVal(i), roundToVal(r) { }
    operator string() {
        stringstream ss;
        ss << flag << " " << name << " " << initVal << " " << roundToVal;
        return ss.str();
    }
};

// 解析一批 A++ 程序，成功返回解析得到的时间复杂度指数幂，失败返回 -1
int parse(const vector<line> &list) {
    vector<bool> stack;                 // 从最外层到最深层语句的循环次数是否含 n，是则此行所在深度对应位置设为 true，否则为 false
    vector<vector<string>> stateStack;  // 当前栈帧
    int stackLevel = 0;                 // 当前行所处于的嵌套语句深度
    _for_print(list, [](line s) -> string { return static_cast<string>(s); });
    for(auto &l : list) {
        _(l.flag), _(l.name), _(l.initVal), _(l.roundToVal);
        if(l.flag == "F") {
            // 栈深度递增
            stackLevel += 1;

            // 储存变量名
            if(stateStack.size() < stackLevel) {
                // 在末尾生成一个新的当前深度的历史变量列表，然后填入变量名
                stateStack.emplace_back();
                stateStack.back().push_back(l.name);
            } else {
                // 直接在当前深度下的位置压入新变量名
                stateStack.at(stackLevel - 1).push_back(l.name);
            }
            
            // 检查变量名是否有重复（注意检查范围仅为当前深度外的当前声明变量，即每个列表的最后一项）
            for(int i = 0; i < stackLevel; ++i) {
                // 错误类型 2 检查
                _(i);
                _(stateStack.at(i).back());
                if(stateStack.at(i).back() == l.name) {
                    __;
                    return -1;
                }
            }

            // 进行变量检查
            bool isAlpha = isalpha(l.initVal.front()) || isalpha(l.roundToVal.front());
            if(stack.size() < stackLevel) stack.push_back(isAlpha);
            else stack.at(stackLevel - 1) = stack.at(stackLevel - 1) || isAlpha;
        } else if(l.flag == "E") {
            // 栈深度递减
            stackLevel -= 1;

            // 错误类型 1 检查
            if(stackLevel < 0){
                __;
                return -1;
            }
        }
    }

    // 检查 stack 中设为真的层个数
    int sum = 0;
    for(auto i : stack) if(i) sum += 1;

    return sum;
}

// 分析输入的表示时间复杂度的字符串，返回输入的时间复杂度指数幂
int getO(const string &str) {
    if(str[2]== '1') return 1;
    else return atoi(str.substr(4, str.size() -1).c_str());
}

int main() {
    int n;
    cin >> n;

    vector<string> ret;
    for(int i = 0; i < n; ++i) {
        // 对每批任务分别读入
        int l;
        string strO;
        cin >> l >> strO;
        _(l);

        // 读入该任务下每一行程序
        vector<line> lines;
        for(int i = 0; i < l; ++i) {
            string flag, name, initVal, roundToVal;
            cin >> flag;
            if(flag == "F") {
                cin >> name >> initVal >> roundToVal;
                line l(flag, name, initVal, roundToVal);
                lines.push_back(l);
            } else if(flag == "E") {
                line l(flag);
                lines.push_back(l);
            }
        }

        int inO = getO(strO);           // 输入的时间复杂度指数幂
        int parsedO = parse(lines);     // 分析出的时间复杂度指数幂
        _(inO), _(parsedO);
        if(parsedO == -1) ret.push_back("ERR");
        else if(inO == parsedO) ret.push_back("Yes");
        else ret.push_back("No");
    }

    for(auto &i : ret) cout << i << endl;

    return 0;
}