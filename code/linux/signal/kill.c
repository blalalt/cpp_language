#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main()
{
  pid_t pid;
  int i;
  int n = 5;
  for (i=0; i<n; i++) {
    pid = fork();
    if (pid == 0) {
      kill(getpid(), SIGKILL);
    }
  }
  return 0;
}
