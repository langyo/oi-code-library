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
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    int count = 1, last, maxCount = 0;
    cin >> last;

    for(int i = 1; i < n; ++i){
        int k;
        cin >> k;
        if(k >= last) ++count, last = k;
        else maxCount = max(maxCount, count), count = 1, last = k;
    }

    cout << maxCount;
    return 0;
}