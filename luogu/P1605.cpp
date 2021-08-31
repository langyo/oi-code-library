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

#define DEBUG
#include "../big_baby.h"

using namespace std;

int main()
{
    // n 为行，m 为列，t 为障碍总数
    int n, m, t;
    cin >> n >> m >> t;

    // 起点坐标为 (sx, sy)，终点坐标为 (fx, fy)
    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    sx -= 1, sy -= 1, fx -= 1, fy -= 1;

    // 地图初始化
    vector<vector<int>> map;
    for (int i = 0; i < n; ++i)
        map.emplace_back(m, 0);

    // 生成障碍；障碍的标识值为 -1
    for (int i = 0; i < t; ++i)
    {
        int x, y;
        cin >> x >> y;
        map[x - 1][y - 1] = -1;
    }

    // DFS 函数
    int state = 0; // 统计路线个数
    function<void(int, int, int)> dfs = [&](int x, int y, int count)
    {
        _(x), _(y), _(count);
        // 边界检查
        if (x < 0 || y < 0 || x >= n || y >= m)
        {
            __;
            return;
        }
        // 有效性检查
        if (map[x][y] != 0)
        {
            __;
            return;
        }
        // 终点检查
        if (x == fx && y == fy)
        {
            // 到达终点，进行标记
            __;
            state += 1;
            return;
        }

        // 标记该点
        map[x][y] = count;
        // 向四个方向搜索
        dfs(x - 1, y, count + 1), dfs(x, y - 1, count + 1), dfs(x + 1, y, count + 1), dfs(x, y + 1, count + 1);
        // 回收该点
        map[x][y] = 0;
    };
    dfs(sx, sy, 1);

    // 输出统计信息
    cout << state << endl;

    return 0;
}