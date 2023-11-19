#include <sys/wait.h>

#include "apue.h"

int main(void) {
  pid_t pid;
  int status;

  if ((pid = fork()) < 0)
    err_sys("fork error");
  else if (pid == 0)
    exit(7);

  if (wait(&status) != pid) err_sys("wait error");
  pr_exit(status);

  if ((pid = fork()) < 0)
    err_sys("fork error");
  else if (pid == 0)
    abort();

  if (wait(&status) != pid) err_sys("wait error");
  pr_exit(status);

  /* コンパイルエラーになる
  wait.c:28:12: warning: division by zero is undefined [-Wdivision-by-zero]
      status /= 0;
             ^  ~
  1 warning generated.
  */
  //   if ((pid = fork()) < 0)
  //     err_sys("fork error");
  //   else if (pid == 0)
  //     status /= 0;

  //   if (wait(&status) != pid) err_sys("wait error");
  //   pr_exit(status);

  exit(0);
}