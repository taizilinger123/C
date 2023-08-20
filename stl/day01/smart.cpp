#include <iostream>
using namespace std;
template<typename T>
class smart_ptr {
public:
   explicit smart_ptr (T* p = NULL): m_p (p) {}
   smart_ptr (smart_ptr<T>& that){
       m_p = that.release();
   }
   ~smart_ptr (void) {
       if (m_p) {
	      delete m_p;
		  m_p = NULL;
	   }
   }
   smart_ptr& operator= (smart_ptr<T>& that){
      if(&that != this)
		  reset(that.release());//转移语义
	  return *this;
   }
   //*号运算符
   T& operator* (void) const {
      return *m_p;
   }
   //->箭头运算符
   T* operator-> (void) const {
      return &**this;
   }
private:
   T* release (void) {
      T* p = m_p;
	  m_p  = NULL;
	  return p;
   }
   void reset (T* p) {
      if (p != m_p) {
	     delete m_p;
		 m_p = p;
	  }
   }
   T* m_p;
};
class A {
public:
  A (void) {
     cout<<"A构造"<<endl;
  }
  ~A (void) {
     cout<<"A析构"<<endl;
  }
  int m_data;
};
int main(void){
   /*
   smart_ptr<A> pa (new A);
   smart_ptr<A> pb (pa);//转移语义，做拷贝构造
   smart_ptr<A> pc;
   pc = pb;//赋值 pc拿着A的地址了
   pc->m_data = 100;
   cout << (*pc).m_data << endl; //指针语义
   */
   smart_ptr<A> pa (new A[3]);
   return 0;
}
