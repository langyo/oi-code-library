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

using namespace std;

long main()
{
  array<int, 10> arr; // 苹果高度数组
  for (long i = 0; i < 10; ++i)
    cin >> arr[i];
  long h; // 陶陶的身高
  cin >> h;

  // 预处理，统统减 30 cm
  for (long i = 0; i < 10; ++i)
    arr[i] -= 30;

  // 开始统计
  long count = 0;
  for (long i = 0; i < 10; ++i)
    if (arr[i] <= h)
      count += 1;

  cout << count;
  return 0;
}