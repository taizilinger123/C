#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void fa(int signo){//信号值
   printf("捕获了信号%d\n",signo);
}

int main(){
   printf("pid=%d\n",getpid());
   signal(SIGINT,fa);
   if(signal(SIGQUIT,SIG_IGN)==SIG_ERR)
	   perror("signal"),exit(-1);
   signal(9,fa);//无效，9不能改变处理方式
   while(1);
}



/*
 root@test:/home/test/biaoc/C/uc/ucday08# a.out
 pid=2369        kill -9 2369
 ^C捕获了信号2   ctrl+c  取消不了
 ^\              ctrl+\  取消不了
root@test:/home/test/biaoc/C/uc/ucday08# kill  -2  2613 
root@test:/home/test/biaoc/C/uc/ucday08# kill  -3  2613 
root@test:/home/test/biaoc/C/uc/ucday08# kill  -9  2613 
root@test:/home/test/biaoc/C/uc/ucday08# kill  -11  2616
root@test:/home/test/biaoc/C/uc/ucday08# kill  -7  2618

root@test:/home/test/biaoc/C/uc/ucday08# a.out
pid=2613
捕获了信号2
已杀死
root@test:/home/test/biaoc/C/uc/ucday08# a.out
pid=2614
段错误 (核心已转储)
root@test:/home/test/biaoc/C/uc/ucday08# a.out
pid=2616
段错误 (核心已转储)
root@test:/home/test/biaoc/C/uc/ucday08# a.out
pid=2618
总线错误 (核心已转储)
 */
