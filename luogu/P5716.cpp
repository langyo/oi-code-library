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
  long year, month;
  cin >> year >> month;

  constexpr array<long, 7> single_months = {1, 3, 5, 7, 8, 10, 12};
  constexpr array<long, 4> double_months = {4, 6, 9, 11};

  if (find(single_months.cbegin(), single_months.cend(), month) != single_months.cend())
  {
    cout << 31;
  }
  else if (find(double_months.cbegin(), double_months.cend(), month) != double_months.cend())
  {
    cout << 30;
  }
  else
  {
    cout << (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 29 : 28);
  }

  return 0;
}
