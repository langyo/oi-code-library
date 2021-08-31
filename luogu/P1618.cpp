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
#include <array>
#include <algorithm>

#define DEBUG
#include "../big_baby.h"

using namespace std;

// 求最大公约数
int gcd(int a, int b)
{
    // 更相减损法，在此鸣谢祖冲之为此算法提供思路
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }

    return a;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    // 化简比例式
    int k = gcd(gcd(a, b), c);
    a /= k, b /= k, c /= k;

    // 枚举所有排列
    array<int, 9> num = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    bool fail_flag = true;
    do
    {
        // 拼接数字
        int concatA = 100 * num[0] + 10 * num[1] + num[2];
        int concatB = 100 * num[3] + 10 * num[4] + num[5];
        int concatC = 100 * num[6] + 10 * num[7] + num[8];
        // 检查比例式的数字是否能与这些数字整除
        if (concatA % a != 0 || concatB % b != 0 || concatC % c != 0)
            continue;
        // 检查比值是否一致
        if (concatA / a == concatB / b && concatB / b == concatC / c)
        {
            fail_flag = false;
            cout << concatA << ' ' << concatB << ' ' << concatC << endl;
        }
    } while (next_permutation(num.begin(), num.end()));

    if (fail_flag)
        cout << "No!!!" << endl;

    return 0;
}
