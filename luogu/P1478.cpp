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
#include <utility>
#include <algorithm>

#define DEBUG
#include "../big_baby.h"

using namespace std;

int main() {
    // 苹果数量，力气
    int n, s;
    // 椅子高度，陶陶最大伸长高度
    int a, b;
    // 苹果列表，分别存储其高度与所费力气
    vector<pair<int, int>> apples;

    cin >> n >> s >> a >> b;
    for(int i = 0; i < n; ++i) {
	// 苹果高度，花费力气
	int x, y;
	cin >> x >> y;
	apples.push_back(make_pair(x, y));
    }

    // 化简数值，将最大高度加起来
    int height = a + b;

    // 根据花费的力气进行升序排列
    sort(apples.begin(), apples.end(), [](const pair<int, int> &l, const pair<int, int> &r) -> bool {
        if(l.second == r.second) {
	    // 如果花费的力气一样，则以所需高度为第二排序依据
	    return l.first < r.first;
	}
	return l.second < r.second;
    });

    // 过一遍苹果列表，统计能摘的苹果数
    int count = 0;
    for(auto &i : apples) {
        if(height >= i.first && s >= i.second) {
	    count += 1;
	    s -= i.second;
	}
    }

    // 输出结果
    cout << count << endl;

    return 0;
}
