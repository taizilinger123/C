#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h> // 引入wait函数所需的头文件

void fa(int signo){
  printf("子进程捕获了信号%d\n", signo);
  exit(0); // 子进程在捕获信号后退出
}

int main(){
  pid_t pid = fork();
  if(pid == 0){
      signal(SIGINT, fa);
      printf("子进程PID: %d\n", getpid());
      pause(); // 让子进程挂起，直到接收到信号
      printf("这行代码不会被执行\n");
  } else {
      printf("父进程PID: %d\n", getpid());
      printf("父进程给子进程发送信号\n");
      kill(pid, SIGINT);
      wait(NULL); // 等待子进程结束
  }
  return 0;
}
