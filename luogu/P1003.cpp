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

using namespace std;

int main()
{
    int n; // 地毯个数
    cin >> n;

    vector<int> a, b, g, k; // 地毯列表
    for (int i = 0; i < n; ++i)
    {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        // 地毯左下角的坐标 (a, b)
        a.push_back(m);
        b.push_back(n);
        // 地毯在 x 轴的宽度
        g.push_back(x);
        // 地毯在 y 轴的宽度
        k.push_back(y);
    }

    int x, y; // 要求的坐标
    cin >> x >> y;

    for (int i = n - 1; i >= 0; --i)
    {
        // 从末尾到开头逐个遍历
        if (
            a[i] <= x &&
            x <= a[i] + g[i] &&
            b[i] <= y &&
            y <= b[i] + k[i])
        {
            cout << i + 1; // 寻找到地毯，输出以 1 开始编号的地毯编号，并直接退出程序
            return 0;
        }
    }

    cout << -1; // 没找到地毯，按照题目要求输出 -1，并退出程序
    return 0;
}