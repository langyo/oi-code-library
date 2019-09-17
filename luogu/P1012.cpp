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
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> list;
    for(auto i = 0; i < n; ++i) {
        string n;
        cin >> n;
        list.push_back(n);
    }

    sort(list.rbegin(), list.rend(), [](const string &l, const string &r) -> bool {
        return l + r < r + l;
    });

    stringstream ss;
    for(auto &i : list) ss << i;

    cout << ss.str() << endl;

    return 0;
}