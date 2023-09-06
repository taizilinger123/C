#include <iostream>
#include <vector>
using namespace std;
void print(vector<int>& vi){
   size_t size = vi.size();
   cout << "大小:" << size << endl;
   for (size_t i = 0; i<size; ++i)
	   cout << vi[i] << ' ';
   cout << endl;
}
void show(const vector<int>& vi){
   for (vector<int>::const_iterator cit = 
	  vi.begin(); cit != vi.end(); ++cit)
	   cout << *cit << ' ';
   cout << endl;
}
void rshow(const vector<int>& vi){
   for (vector<int>::const_reverse_iterator crit = 
	  vi.rbegin(); crit != vi.rend(); ++crit)
	   cout << *crit << ' ';
   cout << endl;
}
int main(void){
   vector<int> v1;
   print (v1);
   vector<int> v2 (10);
   print (v2);
   vector<int> v3 (10, 100);
   print(v3);
   int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
   vector<int> v4 (arr + 2, arr + 6);//30 40 50 60,下一个+6
   print(v4);
   show(v4);
   rshow(v4);
   vector<int>::iterator it = v4.begin() + 2;//it=30+2=50
   *it *= 2;//50*2 = 100
   print(v4);
   v4[2] /= 2;
   print(v4);
   it -= 1; //50 - 1 = 40
   cout<< *it << endl;
   cout<< v4.end() - v4.begin() << endl;//指针和迭代器支持减法不支持加法
   cout<< (v4.begin() < v4.end()) << endl;//1=true
   /*
	vec1.cpp: In function ‘int main()’:
	vec1.cpp:43:8: error: no match for ‘operator<<’ (operand types are ‘std::ostream {aka std::basic_ostream<char>}’ and ‘std::vector<int>::iterator {aka __gnu_cxx::__normal_iterator<int*, std::vector<int> >}’)
	    cout<< v4.begin() < v4.end() << endl;
	这个报错意思是有优先级要加()小括号
	*/
   return 0;
}
