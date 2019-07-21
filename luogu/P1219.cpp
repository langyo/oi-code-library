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

// 暂未 AC

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> pos;
    vector<vector<int>> result;

    function<bool(int, int)> pointState = [&](int x, int y) -> bool {
        return pos.at(x - 1) == y;
    };

    function<void(int)> dfs = [&](int times) {
        _(times);
        _for_print(pos, [](int n) -> int { return n; });
        if(times >= n) {
            // 检查有效性，探测对角线
            bool flag;
            // 左上 - 右下对角线的左上部分
            _print("Left-up part");
            flag = false;
            for(int rowGlobal = 1; rowGlobal <= n; ++rowGlobal) {
                for(int column = 1, row = rowGlobal; column <= rowGlobal; ++column, --rowGlobal) {
                    // TODO: 检查出这里有死循环
                    __;
                    if(flag) {
                        // 不容许出现第二个棋子
                        _print("Second piece!");
                        _(row), _(column);
                        return;
                    }
                    __;
                    if(pointState(row, column)) {
                        _print("First piece!");
                        _(row), _(column);
                        flag = true;
                    }
                }
            }
            // 左上 - 右下对角线的右下部分
            _print("Right-down part");
            flag = false;
            for(int columnGlobal = 2; columnGlobal <= n; ++columnGlobal) {
                for(int row = n, column = columnGlobal; row >= columnGlobal; --row, ++column) {
                    if(flag) {
                        // 不容许出现第二个棋子
                        _print("Second piece!");
                        _(row), _(column);
                        return;
                    }
                    if(pointState(row, column)) {
                        _print("First piece!");
                        _(row), _(column);
                        flag = true;
                    }
                }
            }
            // 右上 - 左下对角线的左下部分
            _print("Left-down part");
            flag = false;
            for(int rowGlobal = 1; rowGlobal <= n; ++rowGlobal) {
                for(int column = 1, row = rowGlobal; column <= (n + 1 - rowGlobal); ++column, ++row) {
                    if(flag) {
                        // 不容许出现第二个棋子
                        _print("Second piece!");
                        _(row), _(column);
                        return;
                    }
                    if(pointState(row, column)) {
                        _print("First piece!");
                        _(row), _(column);
                        flag = true;
                    }
                }
            }
            // 右上 - 左下对角线的右上部分
            _print("Right-up part");
            flag = false;
            for(int columnGlobal = 2; columnGlobal <= n; ++columnGlobal) {
                for(int row = 1, column = columnGlobal; row <= (n + 1 - columnGlobal); ++row, ++column) {
                    if(flag) {
                        // 不容许出现第二个棋子
                        _print("Second piece!");
                        _(row), _(column);
                        return;
                    }
                    if(pointState(row, column)) {
                        _print("First piece!");
                        _(row), _(column);
                        flag = true;
                    }
                }
            }
            // 检查无误，将此情况压入列表
            result.push_back(pos);
        } else {
            for(int i = 1; i <= n; ++i) {
                // 检查是否重复，如有重复，直接跳过这一情况
                bool isRepeat = false;
                for(auto j : pos) {
                    if(i == j) {
                        isRepeat = true;
                        break;
                    }
                }
                if(isRepeat) continue;
                // 将该情况压入当前状态列表，并执行下一层状态搜索
                pos.push_back(i);
                dfs(times + 1);
                pos.pop_back();
            }
        }
    };

    dfs(0);

    for(int i = 0; i < 3; ++i) {
        for(auto j = result.at(i).cbegin(); j != result.at(i).cend() - 1; ++j) cout << *j << " ";
        cout << result.at(i)[result.at(i).size() - 1] << endl; 
    }
    cout << result.size() << endl;

    return 0;
}