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

long main()
{
    vector<int> in;
    for (long i = 0; i < 12; ++i)
    {
        long t;
        cin >> t;
        in.push_back(t);
    }

    long t = 0, save = 0;
    for (long i = 0; i < 12; ++i)
    {
        t += (300 - in[i]);
        save += t / 100;
        t %= 100;
        if (t < 0)
        {
            // 出现钱不够用的情况，直接输出并退出程序，液！
            cout << "-" << i + 1;
            return 0;
        }
    }

    // 输出总额度
    cout << t + save * 120;
    return 0;
}