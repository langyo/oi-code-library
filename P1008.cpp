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
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    short a[10]; // a[i] 表示第 i 个数已经用过了
    for (int i = 192, v = 0; i <= 327; ++i, v = 0){ // 最小 192，最大 327
        memset(a, 0, sizeof(a));
        a[i % 10] = a[i / 10 % 10] = a[i / 100] = a[i * 2 % 10] = a[i * 2 / 10 % 10] = a[i * 2 / 100] = a[i * 3 % 10] = a[i * 3 / 10 % 10] = a[i * 3 / 100] = 1; // 统计数字
        for (int j = 1; j <= 9; ++j)
            v += a[j]; // v 表示 1 - 9 这些数字是否全部齐了
        if (v == 9)
            cout << i << " " << i * 2 << " " << i * 3 << endl;
    }
    return 0;
}