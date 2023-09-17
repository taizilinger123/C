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
  //string s4 = s3.substr(5);
  //string s4 = s3.substr(5, 4);
  //string s4 (s3, 5); //拷贝构造, 从s3的第5个位置构造s4
  string s4 (s3, 5, 4);
  cout << s4 << endl;
  string s5 = "1234";
  //s5[10] = '5'; //吐核心转储错误
  try { 
      s5.at(10) = '5';
  }
  catch (exception& ex) {
      cout << ex.what()<< endl;
  }
  string s6 = "one hello is hello like any other hello";
  string s7 = "hello";
  string s8 = "Tarena";
  pos = 0;
  while((pos = s6.find (s7, pos)) != string::npos){
     s6.replace(pos, s7.size(), s8);
	 pos += s8.size();
  }
  cout << s6 << endl;
  string s9 = "ABCD";
  s9.insert(2, "1234");
  cout << s9 << endl;
  s9.erase (2, 4);
  cout << s9 << endl;
  s9.erase (2);
  cout << s9 << endl;
  s9.erase ();
  cout << s9 << endl;
  string s10 = "XXX", s11 = "YYY";
  s10.swap(s11);//交换了字符串的首地址即指针,效率高,不用像c一样还要引入第三个参数
  cout << s10 << ' ' << s11 << endl;
  s10.assign(s11); //这里将s11的值赋值给s10,assign等同于=号
  cout << s10 << endl;
  return 0;
}


/*
 root@test:/home/test/biaoc/C/stl/day04# g++ string.cpp 
 string.cpp: In function ‘int main()’:
 string.cpp:37:21: error: redeclaration of ‘std::__cxx11::basic_string<char>::size_type pos’
    string::size_type pos = 0;
	                     ^
						 string.cpp:13:21: note: ‘std::__cxx11::basic_string<char>::size_type pos’ previously declared here
						    string::size_type pos = 0;
							                     ^
这个意思是13行先前已经定义过了pos,37行直接用就行，不用再定义了
 */
