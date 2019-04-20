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
#include <regex>
#include <vector>

using namespace std;

int main(){
    string word, document;
    getline(cin, word);
    getline(cin, document);

    string newWord = " ";
    newWord += word;
    newWord += " ";

    vector<int> positions;

    regex r(newWord, regex::icase);
    int count = -1;
    for(
        sregex_iterator it(document.begin(), document.end(), r), end_it;
        it != end_it;
        ++it, ++count, positions.push_back(it -> position())
    );
    
    if(count == 0) cout << -1 << flush;
    else cout << count << flush;

    for(auto &i : positions) cout << " " << i;
    cout << flush;

    return 0;
}