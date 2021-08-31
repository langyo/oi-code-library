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
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <regex>
#include <stdexcept>

using namespace std;

// 未完成

long main()
{
    string inputing;
    regex reg("\\(([1-9]*[0-9])\\,([LR]*)\\)");

    vector<int> list(256, -1); // 存贮节点数据；默认所有节点全部初始化为 -1，代表空节点
    long size = 0;

    // 插入节点函数
    auto insert = [&](long num, string path)
    {
        // 根据路径找到节点下标
        long where = 1;
        for (auto &i : path)
        {
            if (i == 'L')
            {
                where *= 2;
            }
            else if (i == 'R')
            {
                where *= 2;
                where += 1;
            }
            else
                throw invalid_argument("Unknown Path!");
        }

        // 判断节点是否已有数字；此错误由本程序主动自行捕捉
        if (list[where] != -1)
            throw runtime_error("Duplicate Nodes!");

        // 将传入的数字写入对应节点下
        list[where] = num;

        // 更新树的大小
        size = max(size, where + 1);
    };

    // 以 BFS 获得先序遍历的路径列表
    auto BFS = [&]() -> vector<int>
    {
        // 初始化任务队列
        queue<int> task;
        task.push(1);

        // 初始化返回值
        vector<int> ret;

        // 开始遍历
        while (!task.empty())
        {
            long n = task.front();
            task.pop();

            if ((n * 2) != -1)
                task.push(n * 2); // 左
            if ((n * 2 + 1) != -1)
                task.push(n * 2 + 1); // 右

            ret.push_back(list[n]); /* cout << "Called " << n << endl; */
        }

        // 返回结果
        return move(ret);
    };

    while (cin >> inputing, inputing != "()")
    {
        smatch match;
        if (!regex_match(inputing, match, reg))
            throw invalid_argument("Parse falled!");

        long num = stoi(match[1].str());
        string LRs = match[2].str();

        insert(num, LRs);
    }

    auto n = BFS();
    for (auto &i : n)
        cout << i << endl;

    return 0;
}