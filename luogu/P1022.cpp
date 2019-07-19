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
#include <vector>
#include <algorithm>
#include <iomanip>

#define DEBUG
#include "../big_baby.h"

// 暂未 AC

using namespace std;

int main() {
    string expr;
    getline(cin, expr);

    vector<int> left_unknown_weight, right_unknown_weight;
    vector<int> left_constant, right_constant;
    char alpha;

    string left = expr.substr(0, expr.find('='));
    string right = expr.substr(expr.find('=') + 1, expr.size());
    _(left), _(right);

    auto parse = [&](const string &expr, vector<int> &unknown_weight, vector<int> &constant) {
        // 判断开头，此时开头只可能有 - 或任何符号都没有
        string::size_type current_begin_pos;
        _print("New progress");
        if(expr[0] != '-') {
            // 开头为正数
            current_begin_pos = min(expr.find('+'), expr.find('-'));
            string part = expr.substr(0, min(expr.find('+'), expr.find('-')));
            if('a' <= part.back() && part.back() <= 'z') {
                alpha = part.back();
                unknown_weight.push_back(stoi(part.substr(0, part.size() - 1)));
                _for_print(unknown_weight, [](int n) -> int { return n; });
            }
            else {
                constant.push_back(stoi(part));
                _for_print(constant, [](int n) -> int { return n; });
            }
        } else {
            // 开头为负数
            current_begin_pos = min(expr.find('+', 1), expr.find('-', 1));
            string part = expr.substr(1, min(expr.find('+', 1), expr.find('-', 1)));
            if('a' <= part.back() && part.back() <= 'z') {
                alpha = part.back();
                unknown_weight.push_back(-stoi(part.substr(0, part.size() - 1)));
                _for_print(unknown_weight, [](int n) -> int { return n; });
            }
            else {
                constant.push_back(-stoi(part));
                _for_print(constant, [](int n) -> int { return n; });
            }
        }
        // 判断中间部分，此时开头必定会有 + 或 -
        _(expr);
        _(current_begin_pos);
        for(
         string::size_type i = min(expr.find('+', current_begin_pos + 1), expr.find('-', current_begin_pos + 1)),
         last_i = current_begin_pos;;
         last_i = i, i = min(expr.find('+', i + 1), expr.find('-', i + 1))
        ) {
            string part;
            _(i == string::npos ? 't' : 'f');
            if(i != string::npos) part = expr.substr(last_i, i);
            else {
                _(expr);
                _(expr.size());
                part = expr.substr(last_i, expr.size());
            }
            _(last_i), _(i);
            _(part);
            if(part.front() == '+') {
                if('a' <= part.back() && part.back() <= 'z') {
                    alpha = part.back();
                    unknown_weight.push_back(stoi(part.substr(1, part.size() - 1)));
                    _for_print(unknown_weight, [](int n) -> int { return n; });
                } else {
                    constant.push_back(stoi(part.substr(1, part.size())));
                    _for_print(constant, [](int n) -> int { return n; });
                }
            } else if(part.front() == '-') {
                if('a' <= part.back() && part.back() <= 'z') {
                    alpha = part.back();
                    unknown_weight.push_back(-stoi(part.substr(1, part.size() - 1)));
                    _for_print(unknown_weight, [](int n) -> int { return n; });
                } else {
                    constant.push_back(-stoi(part.substr(1, part.size())));
                    _for_print(constant, [](int n) -> int { return n; });
                }
            } else if(i == string::npos) break;
            else _print("Error!");
        }
    };

    parse(left, left_unknown_weight, left_constant);
    parse(right, right_unknown_weight, right_constant);
    
    _print("Reducing...");
    _for_print(left_unknown_weight, [](int n) -> int { return n; });
    _for_print(left_constant, [](int n) -> int { return n; });
    _for_print(right_unknown_weight, [](int n) -> int { return n; });
    _for_print(right_constant, [](int n) -> int { return n; });

    double unknown_weight_sum = 0, constant_sum = 0;
    for(auto &i : left_unknown_weight) unknown_weight_sum += i;
    for(auto &i : right_unknown_weight) unknown_weight_sum -= i;
    for(auto &i : left_constant) constant_sum -= i;
    for(auto &i : right_constant) constant_sum += i;
    _(unknown_weight_sum), _(constant_sum);

    double result = constant_sum / unknown_weight_sum;
    cout << setprecision(3) << result << endl;
    return 0;
}