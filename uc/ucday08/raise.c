#include <stdio.h>
#include <signal.h>

void fa(int signo){
   printf("捕获了信号%d\n",signo);
}
int main(){
   signal(SIGINT,fa);
   int res=sleep(10);//sleep()被非忽略信号中断
   printf("res=%d\n",res);
   raise(3);
   while(1);
}

/*
 root@test:/home/test/biaoc/C/uc/ucday08# a.out
 res=0    #这里让他自动跑完
 退出 (核心已转储)
 root@test:/home/test/biaoc/C/uc/ucday08# a.out
 ^C捕获了信号2  #这里本人按了ctrl+c
 res=7          #信号在第7秒结束
 退出 (核心已转储)
 root@test:/home/test/biaoc/C/uc/ucday08# a.out
 ^C捕获了信号2 
 res=8            
 退出 (核心已转储)
 */
