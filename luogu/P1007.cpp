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
#include <algorithm>

using namespace std;

int main()
{
    int l, n, p;
    int maxValue = 0, minValue = 0;
    cin >> l >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> p;
        maxValue = max(maxValue, max(l - p + 1, p));
        minValue = max(minValue, min(l - p + 1, p));
    }
    cout << minValue << " " << maxValue << endl;
    return 0;
}