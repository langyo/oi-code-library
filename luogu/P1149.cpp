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

// 未完成版本！

#include <cassert>
#include <iostream>
#include <array>
#include <vector>
#include <functional>

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
	
	vector<int> numStack;
	int count = 0, sum = 0;
	function<void(int)> dfs = [&](int num){
		_(numStack.size());
		assert(numStack.size() <= 3);
		numStack.push_back(num);
		count += numStack.back();
		if(count > n || (count == n && numStack.size() < 3)){
			count -= numStack.back();
			numStack.pop_back();
			return;
		}
		
		if(count == n && numStack.size() == 3){
			_print("Success!");
			_(numStack[0]); _(numStack[1]); _(numStack[2]);
			++sum;
			count -= numStack[num];
			numStack.pop_back();
			return;
		}
		else if(numStack.size() == 3) {
		    	_print("Failed.");
		    	_(numStack[0]); _(numStack[1]); _(numStack[2]);
		}
		// 接下来就是 count < n 且 numStack.size() < 3 时做的事了
		for(int i = 0; i < 10; ++i) dfs(i); 
	};
	// 最外层调用
	for(int i = 0; i < 10; ++i) dfs(i);
	
	cout << sum << flush;
	return 0; 
}
