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

using namespace std;

int main()
{
    long height, width;
    cin >> height >> width;

    string in;
    vector<string> map_in;
    for (auto i = 0; i < height; ++i)
    {
        cin >> in;
        map_in.push_back(in);
    }

    vector<string> map_out(map_in);
    for (long line = 0; line < height; ++line)
    {
        for (long pos = 0; pos < width; ++pos)
        {
            if (map_out.at(line).at(pos) == '?')
            {
                // 开始获取八个方向的雷区内容
                long count = 0;

                // 正上，左上，右上
                if (line > 0)
                {
                    // 正上
                    if (map_in.at(line - 1).at(pos) == '*')
                    {
                        count += 1;
                    }
                    // 左上
                    if (pos > 0 && map_in.at(line - 1).at(pos - 1) == '*')
                    {
                        count += 1;
                    }
                    // 右上
                    if (pos < (width - 1) && map_in.at(line - 1).at(pos + 1) == '*')
                    {
                        count += 1;
                    }
                }
                // 正下，左下，右下
                if (line < (height - 1))
                {
                    // 正下
                    if (map_in.at(line + 1).at(pos) == '*')
                    {
                        count += 1;
                    }
                    // 左下
                    if (pos > 0 && map_in.at(line + 1).at(pos - 1) == '*')
                    {
                        count += 1;
                    }
                    // 右下
                    if (pos < (width - 1) && map_in.at(line + 1).at(pos + 1) == '*')
                    {
                        count += 1;
                    }
                }
                // 正左
                if (pos > 0 && map_in.at(line).at(pos - 1) == '*')
                {
                    count += 1;
                }
                // 正右
                if (pos < (width - 1) && map_in.at(line).at(pos + 1) == '*')
                {
                    count += 1;
                }

                // 将附近雷区数量写入输出
                map_out.at(line).at(pos) = to_string(count).at(0);
            }
        }
    }

    for (auto &line : map_out)
    {
        cout << line << endl;
    }

    return 0;
}