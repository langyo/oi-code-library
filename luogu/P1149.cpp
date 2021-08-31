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
#include <array>
#include <vector>

#define DEBUG
#include "../big_baby.h"

using namespace std;

int main()
{
	constexpr array<int, 10> numCount = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

	int k;
	cin >> k;

	if (k <= 10)
	{
		// 能够生成最基本式子的火柴棍个数必须最少也得 10 根（加号、等号、三个一）
		cout << 0 << flush;
		return 0;
	}
	k -= 4; // 去掉加号与等号

	// 累计满足条件的等式数量
	int count = 0;

	// 生成所有有效的候选等式
	typedef pair<pair<int, int>, int> expr_type;
	vector<expr_type> match_list;
	for (int left = 0; left < 1000; ++left)
	{
		for (int right = 0; right < 1000; ++right)
		{
			// 取得各个位的火柴棒个数并加起来
			int n = 0;
			if (left == 0)
				n += numCount[0];
			else
				for (int i = left; i != 0; n += numCount[i % 10], i /= 10)
					;
			if (right == 0)
				n += numCount[0];
			else
				for (int i = right; i != 0; n += numCount[i % 10], i /= 10)
					;
			if (left + right == 0)
				n += numCount[0];
			else
				for (int i = left + right; i != 0; n += numCount[i % 10], i /= 10)
					;
			// 判定是否与所给根数一样
			if (n == k)
			{
#ifdef DEBUG
				cout << left << " + " << right << " = " << left + right << " {" << n << "}" << endl;
#endif
				count += 1;
			}
		}
	}

	// 输出结果
	cout << count << endl;

	return 0;
}
