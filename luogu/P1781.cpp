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

int main()
{
    long n;
    cin >> n;

    vector<pair<string, int>> list;
    for (long i = 1; i <= n; ++i)
    {
        string t;
        cin >> t;
        list.push_back(make_pair(t, i));
    }

    sort(list.begin(), list.end(), [](const pair<string, int> &lhs, const pair<string, int> &rhs) -> bool
         {
             const string &l = lhs.first, &r = rhs.first;
             if (l.size() < r.size())
                 return true;
             if (l.size() > r.size())
                 return false;
             for (auto i = l.cbegin(), j = r.cbegin(); i != l.cend(); ++i, ++j)
             {
                 if (*i < *j)
                     return true;
                 if (*i > *j)
                     return false;
             }
             return false;
         });

    cout << list.back().second << endl
         << list.back().first;

    return 0;
}