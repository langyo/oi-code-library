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
  long n;
  cin >> n;
  cout << (n % 2 == 0 && n > 4 && n <= 12) ? 1 : 0;
  cout << ' ';
  cout << (n % 2 == 0 || n > 4 && n <= 12) ? 1 : 0;
  cout << ' ';
  cout << (n % 2 == 0 && !(n > 4 && n <= 12) || n % 2 != 0 && n > 4 && n <= 12) ? 1 : 0;
  cout << ' ';
  cout << (n % 2 != 0 && !(n > 4 && n <= 12)) ? 1 : 0;
  cout << endl;
  return 0;
}
