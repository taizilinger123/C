#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
template<typename src_iterator, typename dst_iterator>
void my_copy(src_iterator begin, src_iterator end, 
		dst_iterator dst) {
   while (begin != end)
	   *dst++ = *begin++;
}
template<typename iterator>
void my_print(iterator begin, iterator end){
   while (begin != end)
	   cout << *begin++ << ' ';
   cout << endl;
}
int main(void) {
   int a[5] = {10, 20, 30, 40, 50}; //数组
   vector<int> v (5);//向量
   my_copy(a, a + 5, v.begin()); //拷贝数组到向量里面去
   /*
   for(vector<int>::iterator it = v.begin();
		   it != v.end(); ++it)
	     cout << *it << ' ';
   cout << endl;
   */
   my_print(v.begin(), v.end());
   deque<int> d (5); //双端队列
   my_copy(v.begin(), v.end(), d.begin());//拷贝向量vector到双端队列deque里面
   /*
   for (deque<int>::iterator it = d.begin(); 
		   it != d.end(); ++it)
	   cout << *it << " ";
   cout << endl;
   */
   my_print(d.begin(), d.end());
   int b[5];
   my_copy(d.begin(), d.end(), b); //把一个deque拷贝给一个数组,copy就是泛型函数
   /*
   for(int i = 0; i < 5; ++i)
	   cout << b[i] << ' '; //这样子写法是数组输出的每一个数字在一行
   cout << endl;
   */
   my_print(b, b + 5);
   return 0;
}
