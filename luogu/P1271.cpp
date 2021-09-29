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

using namespace std;

int main()
{
  long n, m;
  cin >> n >> m;
  
  vector<long> list;

  for(long i = 0; i < m; ++i)
  {
	  long in;
	  cin >> in;
	  list.push_back(in);
  }

  sort(list.begin(), list.end());

  for(auto &i: list)
  {
	cout << i << " ";
  }

  return 0;
}	
