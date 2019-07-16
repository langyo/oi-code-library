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

#define DEBUG

#ifdef DEBUG
#include <iostream>
#define __ std::cout << "[" << __LINE__ << "] <" << __func__ << "> has been executed." << std::endl
#define _print(str) std::cout << "[" << __LINE__ << "] <" << __func__ << "> : " << str << std::endl
#define _(n) std::cout << "[" << __LINE__ << "] <" << __func__ << "> : " << #n << " = " << (n) << std::endl
#endif

#ifndef DEBUG
#define __ ((void)0)
#define _print(str) ((void)0)
#define _(n) ((void)0)
#endif

using namespace std;

int dfs(int num) {
    num /= 2;

    _(num);

    __;

    _print("test");

    // 边界为碰到 1
    if(num == 1) return 1;
    else {
        int sum = 0;
        for(int i = 1; i < num; ++i) sum += dfs(i);
        return sum;
    }
}

int main() {
    int n;
    cin >> n;

    int out = dfs(n);
    cout << out;

    return 0;
}