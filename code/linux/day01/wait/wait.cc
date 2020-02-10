#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>


int main()
{
  pid_t pid;
  int n = 3;
  int i;
  for (i=0; i<n; i++) {
    pid = fork();

    if (pid == 0) { break; }
    else if (pid > 0) {}
    else { perror("fork error."); exit(1); }
  }

  if (i < n) {
    if (i == 0) {
      execlp("ps", "ps", NULL);
    } else if (i == 1) {
      execlp("./dev_zero", "dev_zero", NULL);
    } else if (i == 2) {
      execlp("./print_zero", "print_zero", NULL);
    }
  } else {
    pid_t wpid;
    int status;
    do {
      wpid = waitpid(-1, &status, WNOHANG);
      if (wpid > 0) {
        if WIFEXITED(status) {
          printf("children pid=%u, exit by %d\n", wpid, WEXITSTATUS(status));
        }

        if WIFSIGNALED(status) {
          printf("children pid=%u, exit by singal %d\n", wpid, WTERMSIG(status));
        }
        n--;
      }
    } while (n);
  }

  return 0;
}
