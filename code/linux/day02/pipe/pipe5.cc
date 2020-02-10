// 使用FIFO进行 ls | wc -l
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
  pid_t pid;

  int ret = mkfifo("__pipe", 0);
  if (ret == -1) {
    perror("pipe error.");
    exit(1);
  }
  pid = fork();

  if (pid == 0) {
    int fd = open("__pipe", O_RDONLY);
    dup2(fd, STDIN_FILENO);
    sleep(2);
    execlp("wc", "wc", "-l", NULL);
  } else if (pid > 0) {
    int fd = open("__pipe", O_WRONLY);
    dup2(fd, STDOUT_FILENO);
    execlp("ls", "ls", NULL);
  } else {
    perror("fork error.");
    exit(1);
  }
  return 0;
}
