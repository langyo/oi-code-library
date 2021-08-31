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

int main()
{
    int B;
    string in1, in2;
    cin >> B >> in1 >> in2;

    vector<short> num1, num2;
    for (auto i = in1.crbegin(); i < in1.crend(); ++i)
    {
        if ('0' <= *i && *i <= '9')
            num1.push_back(static_cast<short>(*i - '0'));
        else
            num1.push_back(static_cast<short>(*i - 'A') + 10);
    }
    for (auto i = in2.crbegin(); i < in2.crend(); ++i)
    {
        if ('0' <= *i && *i <= '9')
            num2.push_back(static_cast<short>(*i - '0'));
        else
            num2.push_back(static_cast<short>(*i - 'A') + 10);
    }

    if (num1.size() > num2.size())
        num1.swap(num2);

    vector<short> sum;
    int temp = 0;
    for (int p = 0; p < num1.size(); ++p)
    {
        temp += num1.at(p) + num2.at(p);
        if (temp > (B - 1))
        {
            sum.push_back(temp - B);
            temp = 1;
        }
        else
        {
            sum.push_back(temp);
            temp = 0;
        }
    }
    for (int p = num1.size(); p < num2.size(); ++p)
    {
        temp += num2.at(p);
        if (temp > (B - 1))
        {
            sum.push_back(temp - B);
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
    {
        if (B < 10)
            cout << *i;
        else
        {
            if ((*i) >= 10)
                cout << static_cast<char>(static_cast<short>('A') + (*i - 10));
            else
                cout << *i;
        }
    }
    cout << endl;

    return 0;
}