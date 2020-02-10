#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  pid_t pid;
  int n = 2;
  int i;
  int fds[2];

  int ret = pipe(fds);
  if (ret == -1) {
    perror("pipe error.");
    exit(1);
  }

  for (i=0; i<n; i++) {
    pid = fork();

    if (pid == 0) { break; }
    else if (pid == -1) {
      perror("fork error.");
      exit(1);
    }
  }

  if (i == 0) {
    printf("i=%d\n", i);
    //close(fds[0]); // close read
    dup2(fds[1], STDOUT_FILENO);
    sleep(2);
    execlp("ls", "ls", "-l", NULL);
  } else if (i == 1) {
    printf("i=%d\n", i);
    sleep(3);
    //close(fds[1]); // close wirte
    dup2(fds[0], STDIN_FILENO);
    execlp("wc", "wc", "-l", NULL);
  } else {
    pid_t wpid;
    int status;
    do {
      wpid = waitpid(-1, &status, WNOHANG);
      if (wpid > 0) {
        printf("child pid=%u died.", wpid);
        n--;
      }
    } while(n);
  }
  return 0;
}
