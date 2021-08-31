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
#include <deque>
#include <string>
#include <utility>

using namespace std;

int main()
{
    long n;
    cin >> n;

    vector<vector<int>> map;
    for (long i = 0; i < n; ++i)
    {
        map.emplace_back();
        for (long j = 0; j < n; ++j)
        {
            long in;
            cin >> in;
            map.back().push_back(in);
        }
    }

    // 染色 BFS，不过这是用来染 -1 的，用在四个边角
    auto bfs = [&](long x, long y)
    {
        deque<pair<int, int>> stack;
        stack.push_back(make_pair(x, y));

        while (!stack.empty())
        {
            auto pos = stack.front();
            stack.pop_front();

            // 边界检查
            if (pos.first < 0 || pos.second < 0 || pos.first >= n || pos.second >= n)
                continue;
            // 有效性检查
            if (map.at(pos.first).at(pos.second) == 1)
                continue;
            if (map.at(pos.first).at(pos.second) == -1)
                continue;

            // 进行染色
            map.at(pos.first).at(pos.second) = -1;
            // 向四个方向进行扩展
            stack.push_back(make_pair(pos.first - 1, pos.second));
            stack.push_back(make_pair(pos.first + 1, pos.second));
            stack.push_back(make_pair(pos.first, pos.second - 1));
            stack.push_back(make_pair(pos.first, pos.second + 1));
        }
    };

    // 从边缘染色
    for (long i = 0; i < n; ++i)
        bfs(0, i), bfs(i, 0), bfs(n - 1, i), bfs(i, n - 1);

    // 染色闭合部分
    for (auto &i : map)
        for (auto &j : i)
            if (j == 0)
                j = 2;
    // 将染成 -1 的部分回滚为 0
    for (auto &i : map)
        for (auto &j : i)
            if (j == -1)
                j = 0;

    // 输出
    for (auto &i : map)
    {
        cout << i.front();
        for (auto j = i.cbegin() + 1; j != i.cend(); ++j)
            cout << " " << *j;
        cout << endl;
    }

    return 0;
}