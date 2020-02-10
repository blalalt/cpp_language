#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
  pid_t pid;
  int fds[2]; // [0]==r, [1]==w
  int ret;
  int n = 4;
  int i;
  ret = pipe(fds);
  if (ret == -1) {
    perror("pipe error.");
    exit(1);
  }
  for (i=0; i<n; i++) {
    pid = fork();
    if (pid == 0) {
      break;
    } else if (pid > 0){}
    else {
      perror("fork error.");
      exit(1);
    }
  }

  if (i < n) {
    close(fds[1]);
    char buf[1000];
    ssize_t size = read(fds[0], buf, 1000);
    printf("%s\n", buf);
  } else if (i == n) {
    close(fds[0]);
    const char* str = "Hello, My child.";
    write(fds[1], str, strlen(str) + 1);
  }
  return 0;
}
