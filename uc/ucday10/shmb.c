#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
  key_t key = ftok(".",100);
  int shmid = shmget(key,0,0);
  if(shmid==-1) perror("shmget"),exit(-1);
  void* p = shmat(shmid,0,0);
  if(p == (void*)-1) perror("shmat"),exit(-1);
  int x = *(int*)p;
  printf("x=%d\n",x);
  shmdt(p);
}

/*
 root@test:/home/test/biaoc/C/uc/ucday10# vi shmb.c
 root@test:/home/test/biaoc/C/uc/ucday10# gcc shmb.c -ob
 root@test:/home/test/biaoc/C/uc/ucday10# b
 x=12345

 */
