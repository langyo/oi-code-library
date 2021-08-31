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

using namespace std;

int main()
{
    long n;
    cin >> n;

    vector<int> list(n + 1, 0);

    // 递推每一个数
    for (long i = 1; i <= n; ++i)
    {
        // 归纳之前的所有结果
        for (long j = 1; j <= i / 2; ++j)
        {
            list[i] += list[j];
        }
        // 它自身不进行拆数，也是一种情况
        list[i] += 1;
    }

    cout << list[n];

    return 0;
}