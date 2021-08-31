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
    long a, b;
    vector<int> list;
    for (long i = 0; i < 7; ++i)
    {
        cin >> a >> b;
        list.push_back(a + b);
    }

    long where = 0, biggest = 0;
    for (long i = 0; i < 7; ++i)
    {
        if (biggest < list[i])
        {
            where = i;
            biggest = list[i];
        }
    }

    cout << where + 1;
    return 0;
}