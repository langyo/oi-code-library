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

using namespace std;

int main() {
    int n;
    cin >> n;

    int i = 0, j = 0;   // 前 i 条斜线一共 j 个数
    while (n > j){
        i += 1;
        j += i;
    }
    if (i % 2 == 1)     // 奇数列，从右往左数
        cout << j - n + 1 << "/" <<  i + n - j;
    else                // 偶数列，从左往右数
        cout << i + n - j << "/" <<  j - n + 1;
    return 0;
}
