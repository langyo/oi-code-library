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
  long need_count;
  array<long, 3> data;
  cin >> need_count;
  for (auto &i : data)
  {
    long per_count, price;
    cin >> per_count >> price;
    i = (need_count % per_count > 0 ? (need_count / per_count + 1) : (need_count / per_count)) * price;
  }
  sort(data.begin(), data.end());
  cout << data[0];

  return 0;
}
