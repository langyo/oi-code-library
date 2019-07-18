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

// 暂未 AC，请勿使用

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

#define DEBUG
#include "../big_baby.h"

using namespace std;

int main()
{
    string word, document;
    
    getline(cin, word);
    getline(cin, document);

    for(auto &i : word) i = tolower(i);
    _(word);
    for(auto &i : document) i = tolower(i);
    _(document);

    vector<int> positions;
    int count = 0;

    for(int p = document.find(word, 0), last_p = 0; p != string::npos; positions.push_back(p), last_p = p, p = document.find(word, last_p));

    if (positions.size() == 0)
        cout << -1 << flush;
    else
        cout << positions.size() << positions.front() << flush;

    return 0;
}