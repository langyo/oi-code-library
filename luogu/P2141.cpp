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
#include <set>

using namespace std;

int main()
{
    long n;
    cin >> n;
    vector<int> list;
    set<int> outCheck;
    for (long i = 0; i < n; ++i)
    {
        long t;
        cin >> t;
        list.push_back(t);
    }

    long count = 0;
    for (long a = 0; a < n - 1; ++a)
    {
        for (long b = a + 1; b < n; ++b)
        {
            if (a != b)
            {
                for (long i = 0; i < n; ++i)
                {
                    if (list[a] + list[b] == list[i])
                        outCheck.insert(list[i]);
                }
            }
        }
    }

    cout << outCheck.size();
    return 0;
}