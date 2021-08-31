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

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> list;
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        list.push_back(t);
    }

    sort(list.begin(), list.end());

    vector<int> out;
    int t = -1;
    for (auto i = list.begin(); i != list.end(); ++i)
    {
        if (*i == t)
            continue;
        else
        {
            t = *i;
            out.push_back(*i);
        }
    }

    cout << out.size() << endl
         << out.front();
    for (auto i = ++out.begin(); i != out.end(); ++i)
    {
        cout << " " << *i;
    }

    return 0;
}