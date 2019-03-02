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
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

/**
 * @todo 该程序仍然有问题，只 AC 了一处
 *       出现问题的原因在于无法正确对编号进行二次排序，只有成绩的一次排序是对的
*/

int main(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> list;
    for(int i = 0; i < n; ++i){
        int k, s;
        cin >> k >> s;
        list.push_back(make_pair(k, s));
    }
    
    m = static_cast<int>(static_cast<double>(m) * 1.5F);
    
    auto sort_by_score = [](const pair<int, int> &lhs, const pair<int, int> &rhs) -> bool {
        if(lhs.second < rhs.second) return true;
        return false;
    };
    sort(list.rbegin(), list.rend(), sort_by_score);
    
    auto sort_by_id = [](const pair<int, int> &lhs, const pair<int, int> &rhs) -> bool {
        if(lhs.first < rhs.first) return true;
        return false;
    };
    for(auto end = list.rbegin(), beg = end; end != list.rend(); ++end){
        if(beg == end) continue;
        if(beg -> second == end -> second) continue;
        else{
            sort(beg, end, sort_by_id);
            beg = end;
            ++beg;
        }
    }
    
    int score_line = list.at(m - 1).second;
    for(; list.at(m).second == score_line; ++m);
    cout << score_line << " " << m << endl;
    for(int i = 0; i < m; ++i){
        cout << list.at(i).first << " " << list.at(i).second << endl;
    }
    
    return 0;
}