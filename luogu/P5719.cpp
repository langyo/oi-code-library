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
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
  long n, k;
  cin >> n >> k;

  long local_sum = 0, count = 0;
  for (long i = k; i <= n; i += k)
  {
    ++count;
    local_sum += i;
  }

  long global_sum = (1 + n) * n / 2;

  cout << setprecision(1) << setiosflags(ios::fixed)
       << static_cast<double>(local_sum) / count << ' '
       << static_cast<double>(global_sum - local_sum) / (n - count) << flush;

  return 0;
}
