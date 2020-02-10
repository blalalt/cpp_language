#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
  int n = 5;
  int i;

  pid_t pid;

  for (i=0; i<n; i++) {
  
    pid = fork();
    if (pid == 0) {
      // children
      break;
    } else if (pid > 0) {
      // farther
      printf("");
    } else {
      perror("fork error.");
      exit(1);
    }
  }

  if (i < n) {
    sleep(i);
    printf("I am %dth child, pid=%u, ppid=%u\n", i+1, getpid(), getppid());
  }else {
    sleep(i);
    printf("I am farther, pid=%u, ppid=%u\n", getpid(), getppid());
  }
}
