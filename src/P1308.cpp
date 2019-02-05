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
#include <map>
#include <string>
#include <cctype>

using namespace std;

// 未完成

string &toslower(string &n){
    for(auto &i : n) i = tolower(i);
    return n;
}

int main(){
    string searching;
    cin >> searching;
    toslower(searching);

    string in;
    map<string, int> list;
    while(cin >> in, in != "0") list;
}