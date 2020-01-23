#include <stdio.h>
#include <stdlib.h> // exit
#include <utmp.h> // for user login info
#include <fcntl.h> // for open function
#include <unistd.h> // for read, close function
#include <time.h> // for ctime function

#define SHOWHOST

void show_info(struct utmp*);
void show_time(long);

int main() 
{
  struct utmp current_record; // save info
  int utmpfd; // file descriptor
  int reclen = sizeof(current_record);

  if ((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1) {
    perror(UTMP_FILE);
    exit(1);
  }

  while (read(utmpfd, &current_record, reclen) == reclen) {
    show_info(&current_record);
  }
  close(utmpfd);
  return 0;
}

void show_info(struct utmp* record) {
  if (record->ut_type != USER_PROCESS) return ;
  printf("% - 8.8s", record->ut_name);
  printf(" ");
  printf("% - 8.8s", record->ut_line); // tty
  printf(" ");
  show_time(record->ut_time);
#ifdef SHOWHOST
  if (record->ut_host[0] != '\0')
    printf("(%s)", record->ut_host);
#endif
  printf("\n");
}

void show_time(long timeval) {
  char* cp = ctime(&timeval);
  printf("% 12.12s", cp+4);
}
