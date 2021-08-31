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
#include <string>
#include <bitset>

using namespace std;

// 该代码为未完善的代码，未正式测试，请勿使用

long main()
{
    // 在此 bitset 中，被置位为 W，未被置位为 L
    bitset<25 * 2500 + 1> map;
    long length = 0;

    string in;
    while (cin >> in)
    {
        if (in.find('E') < 0)
        {
            in = in.substr(0, in.find('E'));
            for (auto &i : in)
            {
                if (i == 'W')
                    map.set(length++);
            }
            break;
        }
        else
        {
            for (auto &i : in)
            {
                if (i == 'W')
                    map.set(length++);
            }
        }
    }

    // 统计 11 分制下的结果
    for (long count = 0; count < length % 11; ++count)
    {
        long W = 0, L = 0;
        for (long i = 0; i < 11; ++i)
        {
            long count_mul = count * 11;
            if (map.test(count_mul + i))
                ++W;
            else
                ++L;
        }
        cout << W << ':' << L << endl;
    }
    ([&]()
     {
         long W = 0, L = 0;
         for (long i = length % 11 * 11; i < length; ++i)
         {
             if (map.test(i))
                 ++W;
             else
                 ++L;
         }
         cout << W << ':' << L << endl;
     })();

    cout << endl;

    // 统计 21 分制下的结果
    for (long count = 0; count < length % 21; ++count)
    {
        long W = 0, L = 0;
        for (long i = 0; i < 21; ++i)
        {
            long count_mul = count * 21;
            if (map.test(count_mul + i))
                ++W;
            else
                ++L;
        }
        cout << W << ':' << L << endl;
    }
    ([&]()
     {
         long W = 0, L = 0;
         for (long i = length % 21 * 21; i < length; ++i)
         {
             if (map.test(i))
                 ++W;
             else
                 ++L;
         }
         cout << W << ':' << L << endl;
     })();

    return 0;
}