#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
  pid_t pid = fork();
  if(pid == 0){//子进程
    printf("子进程%d即将睡眠\n",getpid());
	sleep(4);
	printf("子进程运行结束，返回100\n");
	return 100;//exit(100);
  }
  printf("父进程即将等待\n");
  int res = 0;
  pid_t wpid = wait(&res);//父进程等子进程结束
  printf("等到子进程%d结束res=%d\n",wpid,res);
  if(WIFEXITED(res)){//如果子进程是正常结束
    printf("子进程正常结束\n");
	printf("退出码:%d\n",WEXITSTATUS(res));
  }
}
