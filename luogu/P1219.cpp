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

// 暂未 AC，原因是超时

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> pos;    // pos 下标为行编号，pos 下标下的值为列编号
    vector<vector<int>> result;

    auto check = [&]() -> bool {
        // 只要逐个检查各个排列是否能保证每个子对角线内没有其它子即可
        // 左上 - 右下皇后标记值向量
        vector<int> leftUpToRightDown;
        // 左下 - 右上皇后标记值向量
        vector<int> leftDownToRightUp;
        // 计算每个当前棋子的标记值，并检查两组向量中是否有重复数字，如果有则放弃该方案
        bool continueFlag = false;
        for(int i = 0; i < n; ++i) {
            int row = i + 1, column = pos.at(i);
            // 检查左上 - 右下
            for(auto i : leftUpToRightDown) {
                if(i == (column - row)) {
                    continueFlag = true;
                    break;
                }
            }
            if(continueFlag) break;
            // 检查左下 - 右上
            for(auto i : leftDownToRightUp) {
                if(i == (column + row)) {
                    continueFlag = true;
                    break;
                }
            }
            if(continueFlag) break;
            // 检查通过，写入标记列表
            leftUpToRightDown.push_back(column - row);
            leftDownToRightUp.push_back(column + row);
        }
        return !continueFlag;
    };

    function<void(int)> dfs = [&](int t) {
        if(t == n) {
            if(check()) result.push_back(pos);
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
                dfs(t + 1);
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