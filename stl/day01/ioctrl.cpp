#include <iostream>
#include <sstream>
using namespace std;
template<typename T>
class omanip{
public:
   omanip(ostream& (*fun)(ostream&, T), 
	  T arg):m_fun(fun),m_arg(arg){}
   friend ostream& operator<< (ostream&os, const omanip<T>& om){
      return om.m_fun (os, om.m_arg);
   }
private:
   ostream& (*m_fun)(ostream&, T);
   T m_arg;
};
class debug_args{
public:
   debug_args (const string& file, int line):
	   m_file(file), m_line(line){}
   string m_file;
   int m_line;
};
ostream& debug(ostream& os, debug_args args){
   return os << args.m_file << ':'<<args.m_line<<' ';
}
omanip<debug_args> debug (const char* file, int line){
   return omanip<debug_args> (debug, debug_args(file, line));
}
class color_args{
public:
  color_args(int ctrl, int bg, int fg):m_ctrl(ctrl), m_bg(bg), m_fg(fg) {}
  int m_ctrl;
  int m_bg;
  int m_fg;
};
ostream& color(ostream& os, color_args args){
  if (args.m_ctrl == -1)
	  return os << "\033[0m";
  ostringstream oss;
  oss << "\033[" << args.m_ctrl << ';'
	  << args.m_bg << ';'
	  << args.m_fg << 'm';
  return os << oss.str();
}
omanip<color_args> color (int ctrl = -1, int bg = -1, int fg = -1){
  return omanip<color_args>(color, color_args(ctrl, bg, fg));
}
int main(void){
   cout<<color(1, 44, 33);
   cout<<debug(__FILE__, __LINE__)<<"内存分配失败!"<<endl;
   cout<<color(1, 44, 31);
   cout<<debug(__FILE__, __LINE__)<<"文件打开失败!"<<endl;
   cout<<color();
   return 0;
}
