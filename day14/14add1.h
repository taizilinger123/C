#ifndef   __14ADD1_H__   //如果__14ADD1_H__这个宏没定义则定义这个宏，反之则不定义，一个.c文件包含多次.h文件只编译一次
#define   __14ADD1_H__
void add(int, int);
#endif  //__14ADD1_H__   //这个文件14add1.h要保证其唯一性就__14ADD1_H__这样子定义，以防止同名.h文件的出现
