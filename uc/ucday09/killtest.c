#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h> // 为 exit 函数包含头文件

void fa(int signo){
    printf("子进程捕获了信号%d\n", signo);
    exit(0); // 退出子进程
}

int main(){
    // 在 fork 之前设置信号处理函数
    if (signal(SIGINT, fa) == SIG_ERR) {
        perror("signal");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if(pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(pid == 0) {
        // 子进程
        printf("子进程PID: %d\n", getpid());
        // 使用 pause 等待信号
        pause();
        printf("子进程退出\n");
    } else {
        // 父进程
        printf("父进程PID: %d，子进程PID: %d\n", getpid(), pid);
        printf("父进程给子进程发送SIGINT信号\n");
        kill(pid, SIGINT);
        wait(NULL); // 等待子进程结束
    }
    return 0;
}
