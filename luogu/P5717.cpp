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

using namespace std;

int main()
{
  array<long, 3> in;
  for (auto &i: in) {
    cin >> i;
  }
  sort(in.begin(), in.end());

  if (in[0] + in[1] <= in[2])
  {
    cout << "Not triangle" << endl;
  }
  else
  {
    array<long, 3> squared = {in[0] * in[0], in[1] * in[1], in[2] * in[2]};
    if (squared[0] + squared[1] < squared[2])
    {
      cout << "Obtuse triangle" << endl;
    }
    else if (squared[0] + squared[1] > squared[2])
    {
      cout << "Acute triangle" << endl;
    }
    else
    {
      cout << "Right triangle" << endl;
    }

    if (in[0] == in[1] || in[1] == in[2])
    {
      cout << "Isosceles triangle" << endl;
    }
    if (in[0] == in[1] && in[1] == in[2])
    {
      cout << "Equilateral triangle" << endl;
    }
  }

  return 0;
}
