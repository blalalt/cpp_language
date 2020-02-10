#include <stdio.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>


int main()
{
  pid_t pid;
  char* p;
  p = (char*)mmap(NULL, 1024, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANON, -1, 0);

  pid = fork();
  if (pid == 0) {
    sprintf(p, "Hello, World!");
  } else if (pid > 0) {
    sleep(2);
    printf("%s---\n", p);
  }

  return 0;
}
