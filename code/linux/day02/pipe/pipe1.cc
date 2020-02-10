// 使用管道实现父子进程间通信，完成：ls | wc –l。假定父进程实现ls，子进程实现wc。
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // pipe


int main()
{
  int fds[2];
  pid_t pid;

  int ret = pipe(fds);
  if (ret == -1) {
    perror("pipe error");
    exit(1);
  } else if (ret == 0) { /* successful */ }

  pid = fork();
  if (pid == 0) {
    close(fds[1]);
//    char buf[10000];
//    ssize_t size = read(fds[0], buf, 1000);
    dup2(fds[0], STDIN_FILENO);
    execlp("wc", "wc", "-l", NULL);
  } else if (pid > 0) {
    close(fds[0]);
    dup2(fds[1],STDOUT_FILENO);
    execlp("ls", "ls", NULL);
  } else {
    perror("fork error");
    exit(1);
  }
  return 0;
}
