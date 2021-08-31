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
  long s, v;
  cin >> s >> v;

  // 不停走到学校的最低所需时间
  // 通过余数判断是否需要加一分钟，以补足小数部分进一
  long limit_min = s / v + (s % v == 0 ? 0 : 1);
  // 再额外添加 10 分钟的垃圾分类时间
  limit_min += 10;

  long hh = 8, mm;
  while (limit_min >= 60)
  {
    // 每多 60 分钟，就将时钟向前拨 1 小时
    hh -= 1;
    limit_min -= 60;
    // 如果小时部分超出一天的范围而导致减为负数，将其纠正为整数
    if (hh < 0) {
      hh += 24;
    }
  }
  // 最后向前拨 1 小时，并取余数补足至时钟的分钟部分
  hh -= 1;
  mm = 60 - limit_min;

  cout << ((hh < 10) ? "0" : "") << hh;
  cout << ':';
  cout << ((mm < 10) ? "0" : "") << mm;
  cout << endl;

  return 0;
}
