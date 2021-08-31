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

using namespace std;

int main()
{
    long long base, power, mod;
    cin >> base >> power >> mod;

    cout << base << "^" << power << " mod " << mod << "=";

    long long total = 1;
    while (power > 0)
    {
        if (power % 2 == 1)
            total = total * base % mod;
        base = base * base % mod;
        power = power >> 1;
    }

    cout << total % mod << endl;

    return 0;
}