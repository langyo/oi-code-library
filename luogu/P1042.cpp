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
#include <sstream>

using namespace std;

int main()
{
    // 起初这里的代码使用了 std::bitset，但我意识到这其实是在做过早的无意义优化——原题给的数据范围完全不需要这种等级的空间优化
    // 所以现在展示的代码是直接将读入的字符串存储进内存中的了
    stringstream ss;
    string in;

    while (cin >> in)
    {
        if (in.find('E') != string::npos)
        {
            ss << in.substr(0, in.find('E'));
            in = ss.str();
            break;
        }
        else
        {
            ss << in;
        }
    }

    // 统计 11 分制下的结果
    ([&]
     {
         long W = 0, L = 0;
         for (auto &ch : ss.str())
         {
             if (ch == 'W')
             {
                 W += 1;
             }
             else
             {
                 L += 1;
             }
             if ((W >= 11 || L >= 11) && (W - L >= 2 || L - W >= 2))
             {
                 cout << W << ':' << L << endl;
                 W = 0;
                 L = 0;
             }
         }
         cout << W << ':' << L << endl;
     })();

    cout << endl;

    // 统计 21 分制下的结果
    ([&]
     {
         long W = 0, L = 0;
         for (auto &ch : ss.str())
         {
             if (ch == 'W')
             {
                 W += 1;
             }
             else
             {
                 L += 1;
             }
             if ((W >= 21 || L >= 21) && (W - L >= 2 || L - W >= 2))
             {
                 cout << W << ':' << L << endl;
                 W = 0;
                 L = 0;
             }
         }
         cout << W << ':' << L << endl;
     })();

    return 0;
}