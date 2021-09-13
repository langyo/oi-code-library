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
#include <iomanip>

using namespace std;

int main()
{
  double m, h;
  cin >> m >> h;
  double BMI = m / h / h;
  if (BMI < 18.5)
  {
    cout << "Underweight";
  }
  else if (BMI >= 24)
  {
    cout << setprecision(6) << BMI << endl
         << "Overweight";
  }
  else
  {
    cout << "Normal";
  }
  return 0;
}
