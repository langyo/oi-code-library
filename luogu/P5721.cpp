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

  long count = 1;
  for (long i = n; i >= 1; --i)
  {
    for (long j = 0; j < i; ++j, ++count)
    {
      if (count < 10)
      {
        cout << '0';
      }
      cout << count;
    }
    cout << endl;
  }

  return 0;
}
