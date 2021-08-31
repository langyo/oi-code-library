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

// 仅部分 AC，分数 20

#include <cstdio>
#include <iostream>
#include <array>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    long n, m;
    scanf("%d%d", &n, &m);

    array<int, 100001> back, list;
    for (long i = 0, t; i < n; ++i)
    {
        scanf("%d", &t);
        back.at(i) = t;
        list.at(i) = t;
    }

    array<int, 100001> lTasks, rTasks;
    for (auto i = 0; i < m; ++i)
    {
        long t1, t2;
        scanf("%d%d", &t1, &t2);
        lTasks.at(i) = t1 - 1;
        rTasks.at(i) = t2;
    }

    // 开始处理
    for (auto i = 0; i < m; ++i)
    {
        auto l = lTasks.at(i), r = rTasks.at(i);
        // 排序
        sort(list.begin() + l, list.begin() + r);
        // 计算权值
        long long w = 1, sum = 0, lastNum = -1, lastWeight = 0;
        for (long i = l; i < r; ++i)
        {
            if (lastNum != list.at(i))
            {
                sum += list.at(i) * w;
                lastNum = list.at(i);
                lastWeight = w;
            }
            else
            {
                sum += lastNum * lastWeight;
            }
            w += 1;
        }
        // 输出
        cout << sum << endl;
        // 还原列表
        for (auto j = l; j < r; ++j)
            list.at(j) = back.at(j);
    }

    return 0;
}