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

// 该版本只能部分 AC

#include <cassert>
#include <iostream>
#include <array>
#include <vector>
#include <utility>
#include <sstream>
#include <stdexcept>

#define DEBUG
#include "../big_baby.h"

using namespace std;

int main(){
	constexpr array<int, 10> numCount = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	
	int n;
	cin >> n;
	
	if(n <= 10){
		// 能够生成最基本式子的火柴棍个数必须最少也得 10 根（加号、等号、三个一） 
		cout << 0 << flush;
		return 0;
	}
	n -= 4; // 去掉加号与乘号
	
	// 生成所有有效的候选等式（这部分其实可以打表）
	typedef pair<pair<int, int>, int> expr_type;
	vector<expr_type> match_list;
	for(int left = 0; left < 10; ++left) {
		for(int right = 0; right < 10; ++right) {
			if(left + right < 10) {
				match_list.push_back(make_pair(make_pair(left, right), left + right));
			}
		}
	}

	// 计算候选等式需要的火柴棍个数（不包含加号与等号的 4 根）
	typedef pair<expr_type, int> state_type;
	vector<state_type> state_list;
	for(auto &i : match_list) {
		int sum = numCount[i.first.first] + numCount[i.first.second] + numCount[i.second];
		state_list.push_back(make_pair(i, sum));
	}
	#ifdef DEBUG
	for(auto &n : state_list) {
		cout << n.first.first.first << " + " << n.first.first.second << " = " << n.first.second << " {" << n.second << " + 4 = " << n.second + 4 <<"}" << endl;
	}
	#endif

	// 过滤，统计
	int count = 0;
	for(auto &i : state_list) if(i.second == n) count += 1;

	// 输出结果
	cout << count << endl;

	return 0; 
}
