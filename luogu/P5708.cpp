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
#include <iomanip>

using namespace std;

int main()
{
  double a, b, c;
  cin >> a >> b >> c;

  // 秦九韶公式
  double p = (a + b + c) / 2;
  double result = sqrt(p * (p - a) * (p - b) * (p - c));

  cout << setiosflags(ios::fixed)
       << setprecision(1)
       << result << endl;
  return 0;
}
