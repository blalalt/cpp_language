#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/time.h>
#include <error.h>
#include <errno.h>
#include <stdlib.h>

unsigned my_alarm(unsigned seconds)
{
  struct itimerval new, old;
  new.it_value.tv_sec = (time_t)seconds;
  int ret = setitimer(ITIMER_REAL, &new, NULL);
  if (ret == -1) {
    perror("setitimer error");
    printf("%d\n", errno);
    exit(1);
  }
}
int main()
{
  my_alarm(1);
  for (int i=0; ; i++) {
    printf("%d\n", i);
  }
  return 0;
}
