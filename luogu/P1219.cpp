// luogu-judger-enable-o2
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
#include <algorithm>
#include <functional>
#include <bitset>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> pos; // pos 下标为行编号，pos 下标下的值为列编号
    vector<vector<int>> result;
    int count = 0;

    // 左上 - 右下皇后标记值向量
    bitset<2 * 13 + 1> leftUpToRightDown;
    // 左下 - 右上皇后标记值向量
    bitset<2 * 13 + 1> leftDownToRightUp;
    auto check = [&]() -> bool
    {
        // 只要逐个检查各个排列是否能保证每个子对角线内没有其它子即可
        leftUpToRightDown.reset();
        leftDownToRightUp.reset();
        // 计算每个当前棋子的标记值，并检查两组向量中是否有重复数字，如果有则放弃该方案
        bool continueFlag = false;
        for (int i = 0; i < pos.size(); ++i)
        {
            int row = i + 1, column = pos.at(i);
            int minus = column - row + n, plus = column + row;
            // 检查左上 - 右下
            if (leftUpToRightDown[minus])
            {
                continueFlag = true;
                break;
            }
            // 检查左下 - 右上
            if (leftDownToRightUp[plus])
            {
                continueFlag = true;
                break;
            }
            // 检查通过，写入标记列表
            leftUpToRightDown[minus] = true;
            leftDownToRightUp[plus] = true;
        }
        return !continueFlag;
    };

    bitset<13 + 1> state;
    state.reset();
    function<void(int)> dfs = [&](int t)
    {
        if (t == n)
        {
            if (check())
            {
                count += 1;
                if (count <= 3)
                    result.push_back(pos);
            }
        }
        else
        {
            if (!check())
                return;
            for (int i = 1; i <= n; ++i)
            {
                // 检查是否重复，如有重复，直接跳过这一情况
                if (state.test(i))
                    continue;
                // 将该情况压入当前状态列表，并执行下一层状态搜索
                pos.push_back(i);
                state.set(i);
                dfs(t + 1);
                pos.pop_back();
                state.reset(i);
            }
        }
    };

    dfs(0);

    for (auto &i : result)
    {
        for (auto j = i.cbegin(); j != i.cend() - 1; ++j)
            cout << *j << " ";
        cout << i[i.size() - 1] << endl;
    }
    cout << count << endl;

    return 0;
}
