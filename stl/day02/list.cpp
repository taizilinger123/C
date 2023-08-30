//模仿STL实现一个泛型化的链表容器
#include <iostream>
#include <stdexcept>
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
		if(p->m_data == data){
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
  node*  m_head;//头指针
  node*  m_tail;//尾指针
};
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
}
int main(void){
  test1();
  return 0;
}
