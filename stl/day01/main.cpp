#include <iostream>
using namespace std;
#include "clstempl3.h"
int main(void) {
   Comparator<int> c1 (100, 200);
   cout << c1.max () <<endl;
   cout << c1.min () <<endl;
   Comparator<string> c2 ("hello", "world");
   cout << c2.max () <<endl;
   cout << c2.min () <<endl;
   Comparator<const char*> c3 ("hello", "world");
   cout << c3.max () <<endl;
   cout << c3.min () <<endl;
   return 0;
}
/*
 root@test:/home/test/biaoc/C/stl/day01# g++  main.cpp clstempl3.cpp 
 /tmp/ccKGput4.o：在函数‘main’中：
 main.cpp:(.text+0x30)：对‘Comparator<int>::Comparator(int, int)’未定义的引用
 main.cpp:(.text+0x3f)：对‘Comparator<int>::max() const’未定义的引用
 main.cpp:(.text+0x67)：对‘Comparator<int>::min() const’未定义的引用
 main.cpp:(.text+0xeb)：对‘Comparator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Comparator(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)’未定义的引用
 main.cpp:(.text+0x13a)：对‘Comparator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::max() const’未定义的引用
 main.cpp:(.text+0x17d)：对‘Comparator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::min() const’未定义的引用
 main.cpp:(.text+0x1c0)：对‘Comparator<char const*>::Comparator(char const*, char const*)’未定义的引用
collect2: error: ld returned 1 exit status
root@test:/home/test/biaoc/C/stl/day01# g++  -c  clstempl3.cpp 
root@test:/home/test/biaoc/C/stl/day01# g++  -c  main.cpp
root@test:/home/test/biaoc/C/stl/day01# g++  main.
main.cpp  main.o    
root@test:/home/test/biaoc/C/stl/day01# g++  main.o  clstempl3.
clstempl3.cpp  clstempl3.h    clstempl3.o    
root@test:/home/test/biaoc/C/stl/day01# g++  main.o  clstempl3.o
main.o：在函数‘main’中：
main.cpp:(.text+0x30)：对‘Comparator<int>::Comparator(int, int)’未定义的引用
main.cpp:(.text+0x3f)：对‘Comparator<int>::max() const’未定义的引用
main.cpp:(.text+0x67)：对‘Comparator<int>::min() const’未定义的引用
main.cpp:(.text+0xeb)：对‘Comparator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Comparator(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)’未定义的引用
main.cpp:(.text+0x13a)：对‘Comparator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::max() const’未定义的引用
main.cpp:(.text+0x17d)：对‘Comparator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::min() const’未定义的引用
main.cpp:(.text+0x1c0)：对‘Comparator<char const*>::Comparator(char const*, char const*)’未定义的引用
collect2: error: ld returned 1 exit status
root@test:/home/test/biaoc/C/stl/day01# g++  -c  clstempl3.cpp
root@test:/home/test/biaoc/C/stl/day01# nm  clstempl3.o
                 U strcmp
				 0000000000000000 T _ZNK10ComparatorIPKcE3maxEv
				 000000000000003e T _ZNK10ComparatorIPKcE3minEv
root@test:/home/test/biaoc/C/stl/day01# g++  main.cpp 
root@test:/home/test/biaoc/C/stl/day01# ./a.out 
200
100
world
hello
world
hello
 */
