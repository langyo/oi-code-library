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

using namespace std;

long main()
{
    const string yizhong("yizhong");

    long n;
    cin >> n;
    vector<vector<char>> map;
    vector<vector<bool>> flag;

    for (long i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        map.emplace_back();
        for (auto s : str)
            map.back().push_back(s);
        flag.emplace_back(n, false);
    }

    enum
    {
        Left,
        Right,
        Up,
        Down,
        LeftUp,
        LeftDown,
        RightUp,
        RightDown
    };

    function<bool(int, int, int, int)> dfs = [&](long x, long y, long direction, long strPos) -> bool
    {
        // 边界检查
        if (x < 0 || y < 0 || x >= n || y >= n)
            return false;
        // 有效性检查
        if (map.at(x).at(y) != yizhong.at(strPos))
            return false;
        // 终结检查
        if (strPos == yizhong.size() - 1)
        {
            // 对当前所在点进行标记
            flag.at(x).at(y) = true;
            return true;
        }
        // 向提供的方向搜索
        switch (direction)
        {
        case Left:
            if (dfs(x - 1, y, direction, strPos + 1))
            {
                flag.at(x).at(y) = true;
                return true;
            }
            return false;
        case Right:
            if (dfs(x + 1, y, direction, strPos + 1))
            {
                flag.at(x).at(y) = true;
                return true;
            }
            return false;
        case Up:
            if (dfs(x, y - 1, direction, strPos + 1))
            {
                flag.at(x).at(y) = true;
                return true;
            }
            return false;
        case Down:
            if (dfs(x, y + 1, direction, strPos + 1))
            {
                flag.at(x).at(y) = true;
                return true;
            }
            return false;
        case LeftUp:
            if (dfs(x - 1, y - 1, direction, strPos + 1))
            {
                flag.at(x).at(y) = true;
                return true;
            }
            return false;
        case LeftDown:
            if (dfs(x - 1, y + 1, direction, strPos + 1))
            {
                flag.at(x).at(y) = true;
                return true;
            }
            return false;
        case RightUp:
            if (dfs(x + 1, y - 1, direction, strPos + 1))
            {
                flag.at(x).at(y) = true;
                return true;
            }
            return false;
        case RightDown:
            if (dfs(x + 1, y + 1, direction, strPos + 1))
            {
                flag.at(x).at(y) = true;
                return true;
            }
            return false;
        default:
            // 这种情况理不应当发生
            cerr << "Error at line " << __LINE__ << endl;
            return false;
        }
    };

    // 搜索整幅图里的字符是否与第一个字符相等，有则进行八个方向的搜索
    for (long x = 0; x < n; ++x)
    {
        for (long y = 0; y < n; ++y)
        {
            if (map.at(x).at(y) == yizhong.front())
            {
                // 向八个方向进行搜索
                if (dfs(x - 1, y, Left, 1))
                {
                    flag.at(x).at(y) = true;
                }
                if (dfs(x + 1, y, Right, 1))
                {
                    flag.at(x).at(y) = true;
                }
                if (dfs(x, y - 1, Up, 1))
                {
                    flag.at(x).at(y) = true;
                }
                if (dfs(x, y + 1, Down, 1))
                {
                    flag.at(x).at(y) = true;
                }
                if (dfs(x - 1, y - 1, LeftUp, 1))
                {
                    flag.at(x).at(y) = true;
                }
                if (dfs(x - 1, y + 1, LeftDown, 1))
                {
                    flag.at(x).at(y) = true;
                }
                if (dfs(x + 1, y - 1, RightUp, 1))
                {
                    flag.at(x).at(y) = true;
                }
                if (dfs(x + 1, y + 1, RightDown, 1))
                {
                    flag.at(x).at(y) = true;
                }
            }
        }
    }

    // 打印结果
    for (long i = 0; i < n; ++i)
    {
        for (long j = 0; j < n; ++j)
        {
            if (flag.at(i).at(j))
            {
                cout << map.at(i).at(j);
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}