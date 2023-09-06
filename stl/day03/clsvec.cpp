#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class A {
public:
   A (void) {
       cout << "缺省构造:" << this << endl;
   }
   A (int a): m_a (a){}
   A (const A& that):m_a (that.m_a) {
       cout << "拷贝构造:" << &that << "->" << this << endl;
   }
   ~A(void){
       cout << "析构函数:" << this << endl;
   }
   A& operator= (const A& that){
	   m_a = that.m_a;
       cout << "拷贝赋值:" << &that << "->" << this << endl;
   }
   bool operator== (const A& that) const{
       return m_a == that.m_a;
   }
   bool operator< (const A& that) const{
       return m_a < that.m_a;
   }
   int m_a;
};
int main(void){
	cout << "-------- 1 --------" << endl;
    vector<A> va (3);
	cout << "-------- 2 --------" << endl;
	va.push_back(A());
	cout << "-------- 3 --------" << endl;
	va.pop_back();
	cout << "-------- 4 --------" << endl;
	va.erase(va.begin());
	cout << "-------- 5 --------" << endl;
	va.insert(va.begin(), A());
	cout << "-------- X --------" << endl;
	va.clear();
	va.push_back(A(11));
	va.push_back(A(29));
	va.push_back(A(10));
    vector<A>::iterator it = find (va.begin(), va.end(), A(11));
	if (it == va.end())
		cout << "没找到!" << endl;
	else
	    cout << "找到了:" <<it->m_a << endl;
	sort(va.begin(), va.end());
	for(it = va.begin(); it != va.end(); ++it)
		cout << it->m_a << ' ';
	cout << endl;
	return 0;
}

/*
 /usr/include/c++/5/bits/predefined_ops.h:194:17: error: no match for ‘operator==’ (operand types are ‘A’ and ‘const A’)
   { return *__it == _M_value; }
                    ^
这里提示error, operator==的意思是没有==运算符,需要添加==运算符函数
 */
