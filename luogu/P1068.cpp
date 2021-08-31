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
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

long main()
{
    long n, m;
    cin >> n >> m;

    vector<pair<int, int>> list;
    for (long i = 0; i < n; ++i)
    {
        long k, s;
        cin >> k >> s;
        list.push_back(make_pair(k, s));
    }

    m = static_cast<int>(static_cast<double>(m) * 1.5F);

    sort(list.begin(), list.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) -> bool
         {
             if (lhs.second == rhs.second)
                 return lhs.first < rhs.first;
             return lhs.second > rhs.second;
         });

    long score_line = list.at(m - 1).second;
    for (; list.at(m).second == score_line; ++m)
        ;
    cout << score_line << " " << m << endl;
    for (long i = 0; i < m; ++i)
    {
        cout << list.at(i).first << " " << list.at(i).second << endl;
    }

    return 0;
}