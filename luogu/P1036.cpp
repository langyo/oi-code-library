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

// 尚未完成

#include <iostream>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;

int main() {
    int count;
    cin >> count;

    vector<int> list(count, 0);
    for(auto &i : list) cin >> i;

    int filter_max_prime_num = accumulate(list.begin(), list.end(), 0);

    // 预缓存素数列表
    vector<bool> prime_num_list(filter_max_prime_num + 1, true);
    for(int i = 2; i <= filter_max_prime_num; ++i) {
        if(prime_num_list[i]) {
            for(int j = i * 2; j < filter_max_prime_num; j += i) prime_num_list[j] = false;
        }
    }

    auto dfs = [&]() {

    };

    return 0;
}