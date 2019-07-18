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

/*
    这是什么？

    这是一个大宝贝！

    或者，你可以称它为……超级武器！

    这玩意可以帮助你在无调试器无断点的情况下仍然能看到程序的运行情况！

    把这玩意往程序的各个位置随便插插插吧！~
*/

#ifdef DEBUG
#include <iostream>
#include <string>

template<typename T, typename Str, typename Lambda>
void _for_print_func(T container, Str name, Lambda lamb = ([](std::string str) -> auto { return str; })) {
  std::cout << "[" << __LINE__ << "] <" << __func__ << "> : " << name << " = [";
  if(container.cbegin() == container.cend()) std::cout << "]" << std::endl;
  else if(container.cbegin() + 1 == container.cend()) std::cout << lamb(*(container.cbegin())) << "]" << std::endl;
  else {
    std::cout << lamb(*(container.cbegin()));
    for(auto i = container.cbegin() + 1; i != container.cend(); ++i) std::cout << ", " << lamb(*i);
    std::cout << "]" << std::endl;
  }
}

#define __ std::cout << "[" << __LINE__ << "] <" << __func__ << "> has been executed." << std::endl
#define _print(str) std::cout << "[" << __LINE__ << "] <" << __func__ << "> : " << str << std::endl
#define _for_print(container, lamb) _for_print_func(container, #container, (lamb))
#define _(n) std::cout << "[" << __LINE__ << "] <" << __func__ << "> : " << #n << " = " << (n) << std::endl
#endif

#ifndef DEBUG
#define __ ((void)0)
#define _print(str) ((void)0)
#define _for_print(container, lamb) ((void)0)
#define _(n) ((void)0)
#endif