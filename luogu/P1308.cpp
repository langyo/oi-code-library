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
    const string black = " ";
    document = black + document + black;
    _(document);

    vector<int> positions;

    __;
    for(string::size_type  p = document.find(word, 0), last_p = 0u; p != string::npos; _(p), last_p = p + word.size(), p = document.find(word, last_p)) {
	if(document[p - 1] == ' ' && document[p + word.size()] == ' ') {
	    _print("Find a word!"), _(p);
	    positions.push_back(p);
	}
    }

    __;
    if (positions.size() == 0)
        cout << -1 << endl;
    else
        cout << positions.size() << ' ' << positions.front() - 1 << endl;

    return 0;
}
