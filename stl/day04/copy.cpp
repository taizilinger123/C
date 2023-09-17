#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
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
template<typename iterator, typename function>
void my_for_each(iterator begin, iterator end, function fun){
  while(begin != end)
	  fun(*begin++);
}
template<typename type>
void my_swap(type& a, type& b){
   type c = a;
   a = b;
   b = c;
}
//快速排序,二个参数的比较器快速排序
template<typename iterator>
void my_sort(iterator begin, iterator end){
   iterator pivot = begin;
   iterator last = end;//不能写last = end - 1因为链表这样子写不对
   --last; //这样子写通用
   for(iterator i = begin, j = last; i != j;) {
	  //先处理快速排序的左边
      while (!(i == pivot || *pivot < *i))
		  //*i > *pivot这样子写还要支持大于运算符,所以写<统一支持小于运算符就行了
		  ++i;
		  //iterator迭代器支持==,<,!=,++,*p运算符的
	  if (i != pivot){
		  my_swap(*pivot, *i);
		  pivot = i;
	  }
     //再处理快速排序的右边
	 while (!(j == pivot || *j < *pivot))
	      --j;
	 if (j != pivot) {
	      my_swap(*pivot, *j);
		  pivot = j;
	 }
   }
   iterator it = begin;
   ++it;
   if (pivot != begin && pivot != it)
	   my_sort(begin, pivot);
   it = pivot;
   ++it;
   if (it != end && it != last)
	   my_sort(it, end);
}
//三参数比较器快速排序
template<typename iterator, typename comparator>
void my_sort(iterator begin, iterator end, comparator cmp){
   iterator pivot = begin;
   iterator last = end;//不能写last = end - 1因为链表这样子写不对
   --last; //这样子写通用
   for(iterator i = begin, j = last; i != j;) {
	  //先处理快速排序的左边
      while (!(i == pivot || cmp(*pivot, *i)))
		  //*i > *pivot这样子写还要支持大于运算符,所以写<统一支持小于运算符就行了
		  ++i;
		  //iterator迭代器支持==,<,!=,++,*p运算符的
	  if (i != pivot){
		  my_swap(*pivot, *i);
		  pivot = i;
	  }
     //再处理快速排序的右边
	 while (!(j == pivot || cmp(*j, *pivot)))
	      --j;
	 if (j != pivot) {
	      my_swap(*pivot, *j);
		  pivot = j;
	 }
   }
   iterator it = begin;
   ++it;
   if (pivot != begin && pivot != it)
	   my_sort(begin, pivot, cmp);
   it = pivot;
   ++it;
   if (it != end && it != last)
	   my_sort(it, end, cmp);
}
void add (int& data){
   ++data;
}
class CmpInt {
public:
  bool operator() (int a, int b) const {
      return a > b;
  }
};
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
   my_for_each(d.begin(), d.end(), add);
   my_print(d.begin(), d.end());
   my_for_each(b, b + 5, add);
   my_print(b, b + 5);
   vector<string> vs;
   vs.push_back("beijing");
   vs.push_back("tianjin");
   vs.push_back("weifang");
   vs.push_back("heze");
   vs.push_back("weifang");
   vs.push_back("linyi");
   vs.push_back("qingdao");
   my_sort(vs.begin(), vs.end());
   my_print(vs.begin(), vs.end());
   list<int> l;
   l.push_back(13);
   l.push_back(26);
   l.push_back(19);
   l.push_back(13);
   l.push_back(26);
   l.push_back(37);
   l.push_back(10);
   my_sort(l.begin(), l.end(), CmpInt());
   my_print(l.begin(), l.end());
   return 0;
}
