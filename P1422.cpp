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

int main(){
    int n;
    cin >> n;
    double m;
    if(n <= 150){
        m = 0.4463 * n;
    }else if(150 < n && n <= 400){
        m = 0.4463 * 150 + 0.4663 * (n - 150);
    }else{
        m = 0.4663 * 150 + 0.4663 * 250 + 0.5663 * (n - 400);
    }
    cout << setprecision(1) << fixed << static_cast<int>(m * 10.0 + 0.5) / 10.0;
    return 0;
}