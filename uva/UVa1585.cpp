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

using namespace std;

long main()
{
    long task_count;
    cin >> task_count;

    for (long t = 0; t < task_count; ++t)
    {
        string n;
        long sum = 0, count = 0;

        cin >> n;
        for (auto i : n)
        {
            if (i == 'O')
            {
                ++count;
                sum += count;
            }
            else
            {
                count = 0;
            }
        }
        cout << sum << endl;
    }

    return 0;
}