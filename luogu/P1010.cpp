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
#include <functional>

using namespace std;

long main()
{
    long x;
    cin >> x;

    function<string(int, int, string)> dfs = [&](long x, long i, string s) -> string
    {
        if (x == 0)
            return string("0");
        do
            if (x & 1)
                s = (i == 1 ? "2" : "2(" + dfs(i, 0, "") + ")") + (s == "" ? "" : "+") + s;
        while (++i, x >>= 1);
        return s;
    };

    cout << dfs(x, 0, "") << endl;
}