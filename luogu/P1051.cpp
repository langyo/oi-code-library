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

// 莫名其妙过不了，但数据全对

#include <iostream>
#include <string>

using namespace std;

int main()
{
    long n;
    cin >> n;

    string greatest_name;
    long greatest_money = 0, total_money = 0;

    for (auto i = 0; i < n; ++i)
    {
        string name;
        long score, remark, paper_count;
        string header, western;

        cin >> name >> score >> remark >> header >> western >> paper_count;

        long sum = 0;

        if (score > 80 && paper_count > 0)
            sum += 8000;
        if (score > 85 && remark > 80)
            sum += 4000;
        if (score > 90)
            sum += 2000;
        if (score > 85 && header == "Y")
            sum += 1000;
        if (remark > 80 && western == "Y")
            sum += 850;

        if (sum > greatest_money)
        {
            greatest_money = sum;
            greatest_name = name;
        }

        total_money += sum;
    }

    cout << greatest_name << endl
         << greatest_money << endl
         << total_money;

    return 0;
}