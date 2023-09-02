//模仿STL实现一个泛型化的链表容器
#include <iostream>
#include <stdexcept>
#include <cstring>
using namespace std;
//链表模板
template<typename T>
class list{
public:
  //构造、析构、拷贝构造、拷贝赋值
  list(void):m_head(NULL),m_tail(NULL){}
  ~list(void){
     clear();
  }
/*
const list& that下它的意思：
const: 这表示参数是一个常量，即在函数内部不能修改这个参数的值。
list&: 这是一个引用参数，表示函数将使用传递给它的 list 对象，而不是创建该对象的副本。引用允许在函数内部对传递的对象进行修改，这种修改会影响到函数外部的原始对象。
that: 这是参数的名称，您可以在函数内部使用它来引用传递的 list 对象。
所以，"const list& that" 表示一个常量引用参数，用于传递一个 list 对象给函数，并且函数内部不能修改该对象的值，但可以访问和使用它。这种方式通常用于避免不必要的对象拷贝并提高性能，同时限制了函数对传递对象的修改。""
########################################################################
list(const list& that): m_head(NULL), m_tail(NULL)
这行代码看起来像是一个 C++ 类的拷贝构造函数的定义。让我来解释一下：

list(const list& that): m_head(NULL), m_tail(NULL)
这行代码定义了一个名为 list 的类的拷贝构造函数。拷贝构造函数在创建一个新对象时，使用同一类的另一个对象来初始化它。在这里，that 是传递给拷贝构造函数的参数，用于初始化正在构造的新对象。

具体来说：

list 是类名。
const list& that 是拷贝构造函数的参数，表示传递给构造函数的一个常量引用，这个引用引用了另一个 list 类型的对象。
m_head(NULL), m_tail(NULL) 是初始化列表（initializer list）。它指定了在构造新对象时，成员变量 m_head 和 m_tail 被初始化为 NULL（或者在后续的实现中可能是其他适当的值）。
整体来说，这个拷贝构造函数用于创建一个新的 list 对象，通过传递给它的参数 that 的内容来初始化新对象。这样可以在构造新对象时将另一个对象的状态复制到新对象中，通常用于实现深拷贝。

*/
  list(const list& that): m_head(NULL), m_tail(NULL){
     for(node* p=that.m_head; p; p=p->m_next)
		 push_back(p->m_data);
  }
  list& operator=(const list& that){
      if(&that != this){
	     list temp(that);
		 swap(m_head, temp.m_head);
		 swap(m_tail, temp.m_tail);
	  }
	  return *this;
  }
  //获取首元素
  T& front(void){
	 if(empty())
		 throw underflow_error("链表下溢!");
     return m_head->m_data;
  }
  const T& front(void) const {
     return const_cast<list*>(this)->front();
	 //如何用常量引用使用普通front()函数,链表去常量
  }
  //向首部压入
  void push_front(const T& data){
     /*
	 node* p = new node;
	 p->m_data = data;
	 p->m_prev = NULL;
	 p->m_next = m_head;
	 m_head = p;
	 */
	 m_head = new node(data, NULL, m_head);
	 if(m_head->m_next)
		 m_head->m_next->m_prev = m_head;
	 else
		 m_tail = m_head;
  }
  //从首部弹出
  void pop_front(void){
	 if(empty())
		 throw underflow_error("链表下溢!");
	 node*  next = m_head->m_next;
     delete m_head;
     m_head = next;
	 if(m_head)
	    m_head->m_prev = NULL;
	 else
		m_tail = NULL;
  }
  //获取尾元素
  T& back (void){
     if (empty())
		 throw  underflow_error("链表下溢!");
	 return m_tail->m_data;
  }
  const T& back (void) const {
     return const_cast<list*>(this)->back();
  }
  //向尾部压入
  void push_back(const T& data){
     m_tail = new node(data, m_tail);
	 if (m_tail->m_prev)
		 m_tail->m_prev->m_next = m_tail;
	 else
		 m_head = m_tail;
  }
  //从尾部弹出
  void pop_back(void){
     if (empty())
		 throw  underflow_error("链表下溢!");
	 node* prev = m_tail->m_prev;
	 delete m_tail;
	 m_tail = prev;
	 if (m_tail)
		 m_tail->m_next = NULL;
	 else
		 m_head = NULL;
  }
  //删除所有匹配元素
  void remove(const T& data){
     for (node* p = m_head, *next; p; p=next){
	    next = p->m_next;
		if(equal(p->m_data, data)){
		   if (p->m_prev)
			   p->m_prev->m_next = p->m_next;
		   else
			   m_head = p->m_next;
           if (p->m_next)
			   p->m_next->m_prev = p->m_prev;
		   else
			   m_tail = p->m_prev;
		   delete p;
		}
	 }
  }
  //清空
  void clear(void){
     for(node* next; m_head; m_head = next){
	    next = m_head->m_next;
		delete m_head;
	 }
	 //m_head = NULL; 
	 m_tail = NULL;
  }
  //判空
  bool empty(void) const {
    return m_head == NULL && m_tail == NULL; 
  }
  //获取元素数
  size_t size(void) const{
    size_t counter = 0;
	for (node* p = m_head; p; p = p->m_next)
		++counter;
	return counter;
  }
  //插入输出流
  friend ostream& operator<<(ostream& os, const list& lst){
    for (node* p = lst.m_head; p; p = p->m_next)
		os << *p;
	return os;
  }
private:
  // 节点模板
  class node{
  public:
	node(const T& data, node* prev=NULL, node* next=NULL)
		:m_data(data), m_prev(prev), m_next(next){}
	friend ostream& operator<<(ostream& os,const node& n){
	      cout<<'('<<n.m_data<<')';
	}
	T      m_data;//数据
	node*  m_prev;//前指针
	node*  m_next;//后指针
  };
  /*
   const T& a是什么意思？
   在C++中，const T& a 表示一个常量引用变量，
   其中：
const: 表示变量是一个常量，即它的值不能被修改。
T: 是一个类型名，表示引用变量的数据类型。
&: 表示这是一个引用，即它引用（指向）了另一个对象的内存地址。
a: 是变量的名称。
综合起来，const T& a 表示一个引用变量 a，它引用了一个类型为 T 的对象，而且在程序中不能通过 a 修改该对象的值，因为它被声明为常量引用。这样的声明常常用于避免不必要的数据拷贝，同时提供了一种保护机制，确保在函数或作用域内部不会意外地修改引用的对象。
   */
  //判等函数的通用版本,从右往左看const T& a,就是&a的引用是T的类型，const是修饰&a的,const是修饰a的目标，a是一个引用，引用T类型，T是具有常属性的,看类型都是从右往左看，所以const是修饰a的目标的。
  bool equal(const T& a, const T& b) const {
     return a == b;
  }
  node*  m_head;//头指针
  node*  m_tail;//尾指针
public:
  //正向迭代器
  class iterator {
  public:
     iterator(node* head = NULL, node* tail = NULL, node* p =NULL):m_head (head), m_tail(tail),m_node(p){}
  //判断相等
  bool operator==(const iterator& it) const {
	  return m_node == it.m_node;
  }
  //判断不相等
  bool operator!=(const iterator& it) const {
      return !(*this == it);
  }
  //前加加
  iterator& operator++ (void){
	  if(m_node)
		m_node = m_node->m_next;
	  else
		m_node = m_head;
	  //返回变化的结果
	  return *this;
  }
  //后加加
  const iterator operator++ (int) {
	  iterator old = *this;
	  ++*this;
	  return old;
  }
  //前减减
  iterator& operator-- (void){
	  if (m_node)
		m_node = m_node->m_prev;//双向链表指前指后一样
	  else
	    m_node = m_tail;
	  return *this; //返回调用对象的自引用
  }
  //后减减
  const iterator operator-- (int) {
	  iterator old = *this;
	  --*this;
	  return old;
  }
  //*号运算,取目标
  T& operator* (void) const {
	  return m_node->m_data;
  }
  //箭头运算,取成员
  T* operator-> (void) const {
      return &**this;
  }
  private:
	 node* m_head;
	 node* m_tail;
	 node* m_node;
	 friend class list;
  };
  //获取起始正向迭代器
  iterator begin (void){
     return iterator(m_head, m_tail, m_head);
  }
  //获取终止正向迭代器
  iterator end (void){
     return iterator(m_head, m_tail);
  }
};
//判等函数针对const char*类型的特化版本,(const char* const& a) a是一个长引用，引用的是一个长指针, char*就是代表字符指针。
template<>
bool list<const char*>::equal(const char* const& a, const char* const& b) const {
  return strcmp(a, b) == 0;//strcmp要加头文件#include<cstring>
}
void test1(void){
   list<int> lst1;
   lst1.push_back(50);
   lst1.push_back(60);
   lst1.push_back(50);
   lst1.push_back(70);
   cout << lst1 << endl;// 50 60 50 70
   lst1.push_front(40);
   lst1.push_front(30);
   lst1.push_front(50);
   lst1.push_front(20);
   cout << lst1 << endl;//20 50 30 40 50 60 50 70
   lst1.pop_back();//20 50 30 40 50 60 50
   cout << lst1 << endl;
   lst1.pop_front();//50 30 40 50 60 50
   cout << lst1 << endl;
   ++lst1.front();
   lst1.back() = 40;
   cout << lst1 << endl;//51 30 40 50 60 40
   const list<int>& rlst = lst1;
   //rlst.front()++;
   const list<int>* plst = &lst1;
   //plst->back() = 100;
   list<int> lst2 = lst1;//拷贝构造，深拷贝
   lst1.remove(40);
   cout << lst1 << endl;//51 30 50 60
   cout << lst2 << endl;//51 30 40 50 60 40
   lst1 = lst2;
   lst2.remove(40);
   cout << lst1 << endl;//51 30 40 50 60 40
   cout << lst2 << endl;//51 30 50 60
   cout << lst1.size()<<' '<<lst2.size()<<endl;//6 4
   lst1.clear();
   cout<<boolalpha<<lst1.empty()<<' '<<lst2.empty()<<endl;
}
void test2(void){
  list<string> lst1;
  lst1.push_back("beijing");
  lst1.push_back("tianjin");
  lst1.push_back("shanghai");
  lst1.push_back("beijing");
  lst1.push_back("beijing");
  cout<<lst1<<endl;
  lst1.remove("beijing");
  cout<<lst1<<endl;
}
void test3(void){
  list<const char*> lst1;
  lst1.push_back("beijing");
  lst1.push_back("tianjin");
  lst1.push_back("shanghai");
  lst1.push_back("beijing");
  lst1.push_back("beijing");
  cout<<lst1<<endl;
  char str[] = "beijing";
  lst1.remove(str);
  cout<<lst1<<endl;
}
void test4(void){
  list<int> lst1;
  for(int i = 0; i < 10; ++i)
	  lst1.push_back(i);
  cout<< lst1 << endl;
  for(list<int>::iterator it = lst1.begin();
	 it != lst1.end(); ++it)
	  ++*it;
  cout<< lst1 << endl;
}
int main(void){
  //test1();
  //test2();
  //test3();
  test4();
  return 0;
}
/*
 root@test:/home/test/biaoc/C/stl/day02# vi  list.cpp 
 root@test:/home/test/biaoc/C/stl/day02# g++  list.cpp 
 root@test:/home/test/biaoc/C/stl/day02# ./a.out 
 (50)(60)(50)(70)
 (20)(50)(30)(40)(50)(60)(50)(70)
 (20)(50)(30)(40)(50)(60)(50)
 (50)(30)(40)(50)(60)(50)
 (51)(30)(40)(50)(60)(40)
 (51)(30)(50)(60)
 (51)(30)(40)(50)(60)(40)
 (51)(30)(40)(50)(60)(40)
 (51)(30)(50)(60)
 6 4
true false
(beijing)(tianjin)(shanghai)(beijing)(beijing)
(tianjin)(shanghai)
(beijing)(tianjin)(shanghai)(beijing)(beijing)
(tianjin)(shanghai)
###########################################################

在C++中，a& 和 &a 有不同的含义：

a&：这表示一个引用变量的声明。它用于创建一个引用，将其与现有变量绑定在一起。例如，int x = 42; int& y = x; 将创建一个引用 y，它引用变量 x，并且对 y 的任何操作都会影响到变量 x。

&a：这是取地址运算符，用于获取变量 a 的内存地址。例如，int x = 42; int* ptr = &x; 将创建一个指针 ptr，它存储变量 x 的内存地址。

下面是一个更完整的示例，说明这两者之间的不同：
#include <iostream>
int main() {
    int x = 42;
	int& y = x;   // 创建一个引用 y，绑定到 x
	int* ptr = &x; // 创建一个指针 ptr，存储 x 的地址
    std::cout << "x: " << x << std::endl;     // 输出 x 的值
}
 */
