#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int g_a = 100;

int main()
{

  pid_t pid;

  pid = fork();

  if (pid == 0) {
    printf("child, a=%d\n", g_a);
    sleep(5);
    g_a = 1;
    printf("child, a=%d\n", g_a);
    printf("child exit.\n");
  } else if (pid > 0) {
    while (1) {
      printf("parent, a=%d\n", g_a);
      sleep(1);
    }
  } else {
    perror("fork error.");
    exit(1);
  }

  return 0;
}
