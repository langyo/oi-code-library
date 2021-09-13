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
  long when_begin, count;
  cin >> when_begin >> count;

  long ans = 0;
  for (long i = 0; i < count; ++i)
  {
    if (when_begin <= 5)
    {
      ++ans;
    }
    if (when_begin >= 7)
    {
      when_begin = 1;
    }
    else
    {
      ++when_begin;
    }
  }
  cout << ans * 250;

  return 0;
}
