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
#include <map>
#include <string>

using namespace std;

// 辅助函数，用于计算出下标在一个有限的环中的移动后的位置
long mergeNewIndex(long before, long steps, long max)
{
    before += steps;
    if (before >= max)
        before -= max;
    else if (before < 0)
        before += max;
    return before;
}

long main()
{
    long n, m; // n 为小人个数，m 为指令数
    cin >> n >> m;

    vector<pair<string, bool>> list; // 小人朝向表，true 为朝向圈内，false 为朝向圈外
    for (long i = 0; i < n; ++i)
    {
        string name;
        long t;
        cin >> t >> name;
        pair<string, bool> n(name, t == 0); // t == 0 直接得出逻辑值，true 朝内，false 朝外
        list.push_back(n);
    }

    long index = 0; // 目前定位到的人下标
    for (long i = 0; i < m; ++i)
    {
        long a, s; // a 指示方向，s 指示步数
        cin >> a >> s;
        if (a == 0)
        {
            // 向左数
            if (list[index].second)
            {
                // 朝内
                index = mergeNewIndex(index, -s, n);
            }
            else
            {
                // 朝外
                index = mergeNewIndex(index, s, n);
            }
        }
        else
        {
            // 向右数
            if (list[index].second)
            {
                // 朝内
                index = mergeNewIndex(index, s, n);
            }
            else
            {
                // 朝外
                index = mergeNewIndex(index, -s, n);
            }
        }
    }

    cout << list[index].first;
    return 0;
}