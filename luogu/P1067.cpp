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
#include <sstream>

using namespace std;

int main()
{
    int n;
    cin >> n; // 多项式次数

    stringstream out; // 输出文本流
    for (int i = n; i > 1; --i)
    {
        int a; // 第 i 次项的系数
        cin >> a;
        if (a != 0)
        {
            out << (a > 0 && i != n ? "+" : ""); // 根据需要添加加号；减号无需手动添加，标准库转换数字时自动添加了减号
            if (a == -1)
                out << "-"; // 系数为 -1 时直接加个减号
            else if (a != 1)
                out << a; // 系数为 1 时可以省略的呢
            out << "x^" << i;
        }
    }
    int k;
    // 一次项处理
    cin >> k;
    if (k != 0)
    {
        out << (k > 0 ? "+" : "");
        if (k != 1)
            out << k;
        out << "x";
    }
    // 常数项处理
    cin >> k;
    if (k != 0)
        out << (k > 0 ? "+" : "") << k;

    // 输出
    cout << out.str();
    return 0;
}