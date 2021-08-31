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
  int n;
  cin >> n;

  vector<bool> arr((1 << n), false);
  arr.at(0) = true;

  for (int i = 0; i < (1 << n); ++i)
  {
    for (int j = 1; j < (1 << n) - i; ++j)
      cout << " ";
    for (int j = i; j > 0; --j)
      arr.at(j) = arr.at(j) != arr.at(j - 1);
    if (i % 2 == 0)
      for (int j = 0; j <= i; ++j)
        cout << (arr.at(j) ? "/\\" : "  ");
    else
      for (int j = 0; j <= i; j += 2)
        cout << (arr.at(j) ? "/__\\" : "    ");
    cout << endl;
  }

  return 0;
}