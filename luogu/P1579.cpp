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

#define DEBUG
#include "../big_baby.h"

using namespace std;

int main()
{
    long n;
    cin >> n;

    // 预缓存素数列表
    vector<bool> prime_num_list(n + 1, true);
    for (long i = 2; i <= n; ++i)
    {
        if (prime_num_list[i])
        {
            for (long j = i * 2; j < n; j += i)
                prime_num_list[j] = false;
        }
    }
    prime_num_list[0] = false;
    prime_num_list[1] = false;

    // 哥德巴赫猜想所指示的 3 个素数有两种情况（给出的数字 > 9）：
    // [1] 两个偶数，一个奇数
    // [2] 三个奇数

    // 情况 [1]
    // 因为只有 2 是偶数中的素数，所以前两个数字必定为 2，只需要再判断最后的 n - 4 是否为素数即可
    if (prime_num_list[n - 4])
    {
        cout << 2 << " " << 2 << " " << n - 4 << endl;
        return 0; // 直接结束程序
    }

    // 情况 [2]
    // 前两个数字暴力枚举，不过限定范围在奇数集，第三个数字直接减，然后逐个检查
    for (long a = 3; a <= n; a += 2)
    {
        for (long b = 3; b <= n; b += 2)
        {
            long c = n - a - b;
            if (prime_num_list[a] && prime_num_list[b] && prime_num_list[c])
            {
                cout << a << " " << b << " " << c << endl;
                return 0; // 直接结束程序
            }
        }
    }

    _print("Wait...Why did the program go there?!");
    return 0;
}