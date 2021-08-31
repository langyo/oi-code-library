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
  double m, t, s;
  cin >> m >> t >> s;

  // 除零检查
  if (s <= 0 || m <= 0)
  {
    // 才吃 0 分钟，或者根本没有苹果，都直接输出最初的苹果数量
    cout << m << endl;
    return 0;
  }
  if (t <= 0)
  {
    // 0 分钟吃完一个苹果，神速啊，那你肯定是不论吃多久都直接不剩的了
    cout << 0 << endl;
    return 0;
  }

  // 溢出检查
  if (m - s / t < 0) {
    // 早就吃完了，不能再吃了
    cout << 0 << endl;
    return 0;
  }

  cout << static_cast<long>(m - s / t) << endl;
  return 0;
}
