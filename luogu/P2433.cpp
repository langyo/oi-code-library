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
#include <cmath>

using namespace std;

int main()
{
  constexpr auto pi = 3.141593;

  // P.S. 尽管我碰到过各种恶心的业务需求，但这么鬼畜的还是第一次
  long problem_id;
  cin >> problem_id;
  switch (problem_id)
  {
  case 1:
    cout << "I love Luogu!";
    break;
  case 2:
    cout << 6 << ' ' << 4;
    break;
  case 3:
    cout << 3 << endl
         << 12 << endl
         << 2;
    break;
  case 4:
    cout << "166.667";
    break;
  case 5:
    cout << 15;
    break;
  case 6:
    cout << sqrt(6 * 6 + 9 * 9);
    break;
  case 7:
    cout << 110 << endl
         << 90 << endl
         << 0;
    break;
  case 8:
    cout << pi * 5 * 2 << endl
         << pi * 5 * 5 << endl
         << pi * 5 * 5 * 5 * 4 / 3;
    break;
  case 9:
    cout << 22;
    break;
  case 10:
    cout << 9;
    break;
  case 11:
    cout << 100.0 / 3;
    break;
  case 12:
    cout << 13 << endl
         << 'R';
    break;
  case 13:
    cout << static_cast<long>(pow(pi * 4 * 4 * 4 * 4 / 3 + pi * 10 * 10 * 10 * 4 / 3, 1.0 / 3));
    break;
  case 14:
    cout << 50;
    break;
  }
  cout << flush;
  return 0;
}
