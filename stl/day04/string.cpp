#include <iostream>
using namespace std;
int main(void) {
  string s1 ("hello ");
  string s2 ("world 1234");
  //s1 += s2;
  //s1.append(s2);
  //从s2的第6个字符开始(从0开始算)取4个字符加到s1的末尾
  s1.append(s2, 6, 4);
  cout << s1 << endl;
  string s3 = "abcd,efgh.ijkl!mnop?qrst'uvw:xyz";
  size_t counter = 0;
  string::size_type pos = 0;
  //find_first_of寻找第一个
 while ((pos = s3.find_first_of(",.!?':", pos)) 
		 != string::npos){
        ++counter;
		++pos;
 }
  cout << counter << "个标点。" << endl;
  return 0;
}
