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
   return 0;
}
