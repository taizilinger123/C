#ifndef _CLSTEMPL3_H
#define _CLSTEMPL3_H
template<typename T>
class Comparator {
public:
    Comparator (T x, T y); //构造函数 
    T max (void) const;
	T min (void) const;
private:
	T m_x;
	T m_y;
};
#include "clstempl3.cpp"
#endif // _CLSTEMPL3_H
