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
#include <sstream>

using namespace std;

int main()
{
    long p1, p2, p3;
    string s;
    stringstream out;

    cin >> p1 >> p2 >> p3 >> s;
    for (long i = 0; i < s.size(); ++i)
    {
        if (s[i] != '-')
            out << s[i];
        else if ((i == 0 || i == s.size() - 1) && s[i] == '-')
            out << '-';
        else if (s[i] == '-' && (s[i - 1] == '-' || s[i + 1] == '-'))
            out << '-';
        else if (s[i] == '-')
        {
            if (s[i - 1] >= s[i + 1] || (s[i - 1] < 58 && s[i + 1] > 96))
                out << '-';
            else if (s[i + 1] == s[i - 1] + 1)
                continue;
            else
            {
                if (p1 == 3)
                {
                    for (long k = 1; k <= (s[i + 1] - s[i - 1] - 1) * p2; ++k)
                        out << '*';
                }
                else if (s[i + 1] <= 57 && s[i + 1] >= 48 && s[i - 1] <= 57 && s[i - 1] >= 48)
                {
                    if (p3 == 1)
                    {
                        for (char k = s[i - 1] + 1; k <= s[i + 1] - 1; ++k)
                            for (long j = 1; j <= p2; j++)
                                out << k;
                    }
                    else if (p3 == 2)
                    {
                        for (char k = s[i + 1] - 1; k >= s[i - 1] + 1; --k)
                            for (long j = 1; j <= p2; j++)
                                out << k;
                    }
                }
                else if (s[i + 1] <= 122 && s[i + 1] >= 97 && s[i - 1] <= 122 && s[i - 1] >= 97)
                {
                    if (p1 == 1)
                    {
                        if (p3 == 1)
                        {
                            for (char k = s[i - 1] + 1; k <= s[i + 1] - 1; ++k)
                                for (long j = 1; j <= p2; j++)
                                    out << k;
                        }
                        else if (p3 == 2)
                        {
                            for (char k = s[i + 1] - 1; k >= s[i - 1] + 1; --k)
                                for (long j = 1; j <= p2; j++)
                                    out << k;
                        }
                    }
                    else if (p1 == 2)
                    {
                        if (p3 == 1)
                        {
                            for (char k = s[i - 1] + 1; k <= s[i + 1] - 1; ++k)
                                for (long j = 1; j <= p2; j++)
                                    out << static_cast<char>(k - 32);
                        }
                        else if (p3 == 2)
                        {
                            for (char k = s[i + 1] - 1; k >= s[i - 1] + 1; --k)
                                for (long j = 1; j <= p2; j++)
                                    out << static_cast<char>(k - 32);
                        }
                    }
                }
            }
        }
    }
    cout << out.str();
    return 0;
}