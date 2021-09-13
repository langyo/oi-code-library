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
#include <array>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
  array<long, 3> in;
  string order;
  for (auto &i : in)
  {
    cin >> i;
  }
  cin >> order;
  sort(in.begin(), in.end());

  long count = 0;
  for (auto ch : order)
  {
    switch (ch)
    {
    case 'A':
      cout << in[0];
      break;
    case 'B':
      cout << in[1];
      break;
    case 'C':
      cout << in[2];
      break;
    }
    if (count < 2)
    {
      cout << ' ';
      ++count;
    }
  }
  cout << flush;

  return 0;
}
