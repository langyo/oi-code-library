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
#include <sstream>
#include <iomanip>

#define DEBUG
#include "../big_baby.h"

using namespace std;

long main()
{
    string expr;
    getline(cin, expr);

    bool isPlus = true;     // 当前正负情况；如果为真则符号为加，否则为减
    bool isLeft = true;     // 当前等式方向；如果为真则为左半部分，否则为右半部分
    bool isUnknown = false; // 当前数字归属状态；如果为真则为未知数系数，否则为常数项
    bool hasNum = false;    // 当前状态是否已填写过数字；这是判断未知数是否有系数的依据，用于自动填充未知数系数为 1
    long long num = 0;      // 数字缓存

    // 注意，下面的两个累积和都是算作等式左边的，这是为了减少判断部分的复杂度
    long unknown_weight = 0; // 未知数权值
    long constant = 0;       // 常数值
    char alpha = 'a';       // 未知数符号

    // 运算器函数
    auto evaluator = [&]()
    {
        if ((isPlus && isLeft) || ((!isPlus) && (!isLeft)))
        {
            // 在左侧且为加法，或在右侧且为减法
            if (isUnknown && hasNum)
                unknown_weight += num;
            else if (isUnknown && (!hasNum))
                __, unknown_weight += 1;
            else
                constant += num;
        }
        else if (((!isPlus) && isLeft) || (isPlus && (!isLeft)))
        {
            // 在左侧且为减法，或在右侧且为加法
            if (isUnknown && hasNum)
                unknown_weight -= num;
            else if (isUnknown && (!hasNum))
                __, unknown_weight -= 1;
            else
                constant -= num;
        }
    };

    // 遍历整个字符串
    for (string::size_type i = 0; i < expr.size(); ++i)
    {
        char ch = expr[i]; // 当前游标所在字符
        _(ch), _(isLeft), _(isPlus), _(isUnknown), _(hasNum), _(num), _(unknown_weight), _(constant);
        if (ch == '+')
        {
            // 处理上一个符号对应数字的加减操作
            evaluator();
            // 设置下一状态
            isPlus = true;
            isUnknown = false;
            hasNum = false;
            num = 0;
        }
        if (ch == '-')
        {
            // 处理上一个符号对应数字的加减操作
            evaluator();
            // 设置下一状态
            isPlus = false;
            isUnknown = false;
            hasNum = false;
            num = 0;
        }
        if (ch == '=')
        {
            // 处理上一个符号对应数字的加减操作
            evaluator();
            // 设置下一状态
            isLeft = false;
            isUnknown = false;
            isPlus = true;
            hasNum = false;
            num = 0;
        }
        if ('a' <= ch && ch <= 'z')
        {
            alpha = ch;
            isUnknown = true;
        }
        if ('0' <= ch && ch <= '9')
        {
            hasNum = true;
            num = num * 10 + static_cast<int>(ch) - static_cast<int>('0');
        }
    }
    // 最后一次处理数字加减操作
    evaluator();

    // 计算结果
    double result;
    _(unknown_weight), _(constant);
    if (unknown_weight == 0 || constant == 0)
        result = 0.0;
    else
        result = -static_cast<double>(constant) / static_cast<double>(unknown_weight);

    cout << alpha << "=" << setiosflags(ios::fixed) << setprecision(3) << result << endl;
    return 0;
}