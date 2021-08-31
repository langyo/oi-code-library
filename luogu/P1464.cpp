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
#include <functional>
#include <utility>

#define DEBUG
#include "../big_baby.h"

using namespace std;

struct args_t
{
    long long a, b, c;
    args_t(long long _a, long long _b, long long _c) : a(_a), b(_b), c(_c) {}

    bool check(long x, long y, long z)
    {
        return x == a && y == b && z == c;
    }
};

int main()
{
    vector<args_t> init_list;
    long long inA = 0, inB = 0, inC = 0;
    cin >> inA >> inB >> inC;
    while (!(inA == -1 && inB == -1 && inC == -1))
    {
        args_t args(inA, inB, inC);
        init_list.push_back(args);
        cin >> inA >> inB >> inC;
    }

    // 纯函数执行缓存
    vector<pair<args_t, long long>> cache;

    // 纯函数 w
    function<long long(long long, long long, long long)> w = [&](long long a, long long b, long long c) -> long long
    {
        // 检查缓存
        for (auto &i : cache)
        {
            if (i.first.check(a, b, c))
            {
                _print("Using cache:");
                _(a), _(b), _(c);
                _(i.second);
                return i.second;
            }
        }

        // 缓存中没有，现场计算
        if (a <= 0 || b <= 0 || c <= 0)
            return 1;
        if (a > 20 || b > 20 || c > 20)
            return w(20, 20, 20);

        long ret;
        if (a < b && b < c)
        {
            ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
            args_t args(a, b, c);
            cache.push_back(make_pair(args, ret));
            return ret;
        }
        ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
        args_t args(a, b, c);
        cache.push_back(make_pair(args, ret));
        return ret;
    };

    // 正式开始计算
    for (auto &i : init_list)
    {
        long ret = w(i.a, i.b, i.c);
        cout << "w(" << i.a << ", " << i.b << ", " << i.c << ") = " << ret << endl;
    }

    return 0;
}