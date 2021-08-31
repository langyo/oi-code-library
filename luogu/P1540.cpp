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
#include <deque>

using namespace std;

long main()
{
    long m, n;
    cin >> m >> n; // m 为内存容量，n 为文章长度

    deque<int> q;  // 当前内存队伍
    long count = 0; // 访问外存次数
    for (long i = 0; i < n; ++i)
    {
        long in;
        cin >> in;
        // 检查内存里有没有 in，如果有就无需做任何操作，如果没有就得访问外存
        if (find(q.begin(), q.end(), in) == q.end())
        {
            // 内存里没有，先检查内存满没满
            if (q.size() == m)
            {
                // 将最开头的那个丢掉
                q.pop_front();
            }
            // 向末尾添加新缓存数据
            q.push_back(in);
            // 递增访问次数
            ++count;
        }
    }

    cout << count;
    return 0;
}