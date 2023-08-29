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
  list(const list& that){
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
  void clear(void){}
  //判空
  bool empty(void) const {}
  //获取元素数
  size_t size(void) const{}
  //插入输出流
  friend ostream& operator<<(ostream& os, const list& lst){}
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
int main(void){
  return 0;
}
