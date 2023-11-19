#include <sys/wait.h>

#include "apue.h"

int main(void) {
  pid_t pid;

  if ((pid = fork()) < 0) {
    err_sys("fork error");
  } else if (pid == 0) {
    // (*)fork_8.3.cで確認した通り、子プロセスは親プロセスの変数を変更更新できない
    if ((pid = fork()) < 0)
      err_sys("fork error");
    else if (pid > 0)
      exit(0);

    sleep(2);
    printf("second child, parent pid = %ld\n", (long)getppid());
    exit(0);
  }

  // (*)より、ここでのpidは子プロセスのpid（孫ではない）
  if (waitpid(pid, NULL, 0) != pid) err_sys("waitpid error");

  exit(0);
}