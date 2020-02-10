#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

int main()
{
  pid_t pid;
  int fd = open("output.txt", O_RDWR | O_CREAT);
  dup2(fd, STDOUT_FILENO);

  pid = fork();
  if (pid == 0) {
    execlp("ps", "ps", "aux", NULL);
  } else if (pid > 0) {
    pid_t wpid;
    wpid = wait(NULL);
  }
  return 0;
}
