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
#include <algorithm>

using namespace std;

long main()
{
    string in1, in2;
    cin >> in1 >> in2;

    vector<short> num1, num2;
    for (auto i = in1.crbegin(); i < in1.crend(); ++i)
        num1.push_back(static_cast<short>(*i - '0'));
    for (auto i = in2.crbegin(); i < in2.crend(); ++i)
        num2.push_back(static_cast<short>(*i - '0'));

    if (num1.size() > num2.size())
        num1.swap(num2);

    vector<short> sum;
    long temp = 0;
    for (long p = 0; p < num1.size(); ++p)
    {
        temp += num1.at(p) + num2.at(p);
        if (temp > 9)
        {
            sum.push_back(temp - 10);
            temp = 1;
        }
        else
        {
            sum.push_back(temp);
            temp = 0;
        }
    }
    for (long p = num1.size(); p < num2.size(); ++p)
    {
        temp += num2.at(p);
        if (temp > 9)
        {
            sum.push_back(temp - 10);
            temp = 1;
        }
        else
        {
            sum.push_back(temp);
            temp = 0;
        }
    }
    if (temp > 0)
        sum.push_back(temp);

    for (auto i = sum.crbegin(); i != sum.crend(); ++i)
        cout << *i;
    cout << endl;

    return 0;
}