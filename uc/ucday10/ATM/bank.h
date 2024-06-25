//客户端和服务器端公用的头文件
#ifndef BANK_H_
#define BANK_H_
//声明两个key值，用来给消息队列用，这两个key

extern const int key1;//客户端向服务器发送
extern const int key2;//服务器向客户端发送

//消息类型  定义为各种宏 方便处理
#define M_OPEN 1//代表开户类型
#define M_DESTROY 2 //销户
#define M_SAVE 3   //存钱
#define M_TAKE 4   //取钱
#define M_QUERY 5  //查询
#define M_TRANSF 6 //转账
#define M_SUCCESS 7 //处理成功
#define M_FAILED 8 //处理失败

//包含账户信息的账户结构体
struct Account{
  int id;//账号
  char name[10];//用户名
  char password[10];//密码
  double balance;//金额
};

//消息的结构体
struct Msg{
  long mtype;//消息的类型
  struct Account acc;//账户的信息结构体
};
#endif
