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
#include <numeric>

#define DEBUG
#include "../big_baby.h"

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> list(n, 0);
    for(auto &i : list) cin >> i;

    int filter_max_prime_num = accumulate(list.begin(), list.end(), 0);
    _(filter_max_prime_num);

    // 预缓存素数列表
    vector<bool> prime_num_list(filter_max_prime_num + 1, true);
    for(int i = 2; i <= filter_max_prime_num; ++i) {
        if(prime_num_list[i]) {
            for(int j = i * 2; j < filter_max_prime_num; j += i) prime_num_list[j] = false;
        }
    }

    typedef decltype(list.begin()) I;
    int count = 0;

    function<void(I, I, int, int)>  dfs = [&](I begin, I end, int sum, int last_k) {
	_print("Enter a new stack level:");
	_(sum), _(last_k);
	_print("------");
	if(last_k == 0) {
	    _print("DFS succeed.");
	    if(prime_num_list[sum]) _print("Get a new prime number"), _(sum), count += 1, _(count);
	    return;
	}
	for(auto i = begin; i != end; ++i) {
	    dfs(i + 1, end, *i + sum, last_k - 1);
	}
	_print(begin == end ? "DFS failed." : "");
    };
    dfs(list.begin(), list.end(), 0, k);

    cout << count << endl;

    return 0;
}
