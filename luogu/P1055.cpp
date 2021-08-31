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
#include <regex>

using namespace std;

int main()
{
  const regex ISBNReg("([0-9])\\-([0-9])([0-9])([0-9])\\-([0-9])([0-9])([0-9])([0-9])([0-9])\\-(.)"); // 用于匹配 ISBN 的正则表达式
  smatch match;                                                                                       // 匹配得到的结果存储变量
  string in;                                                                                          // 输入的原始 ISBN
  cin >> in;

  regex_match(in, match, ISBNReg); // 进行匹配
  vector<int> subIntList;          // 存储每个数字的数组
  for (int i = 1; i < 10; ++i)
    subIntList.push_back(stoi(match[i].str())); // 提取由正则匹配到的前九个数字
  char matchCode = match[10].str()[0];          // 最后一位字符

  int code = 0; // 由机器生成的校验码存储变量
  for (int i = 0; i < 9; ++i)
    code += subIntList[i] * (i + 1);
  code %= 11;
  char codeToChar = code == 10 ? 'X' : to_string(code)[0];

  if (matchCode == codeToChar)
    cout << "Right";
  else
    cout << in.substr(0, 12) << codeToChar;

  return 0;
}