#ifndef EMP_H
#define EMP_H
#include <string>
using namespace std;
   class Emp{
      string name;
	  int    age;
	  double salary;
	  public:
      Emp();
	  void show();
	  void setName(string name);
   };
#endif

/*
 root@test:/home/test/biaoc/C/C++/day03/emp# vi  emp.h
 root@test:/home/test/biaoc/C/C++/day03/emp# g++  emp.h 
 root@test:/home/test/biaoc/C/C++/day03/emp# ls
 emp.h  emp.h.gch
 root@test:/home/test/biaoc/C/C++/day03/emp# vi emp.h.gch 
 root@test:/home/test/biaoc/C/C++/day03/emp# ls
 emp.h  emp.h.gch
 root@test:/home/test/biaoc/C/C++/day03/emp# rm  *gch
 */
