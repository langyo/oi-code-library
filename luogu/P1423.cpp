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
  double in, length = 2.0, ans = 0.0; // length 为当前步能游的距离，ans 为已游总距离
  int step = 0;                       // step 为计量的步数
  cin >> in;

  for (; ans < in; ans += length, length *= 0.98, ++step)
    ;
  cout << step;
  return 0;
}