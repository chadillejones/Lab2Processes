#include  <stdio.h>
#include  <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
  int status;

  pid_t child_a, child_b, wpid;

  child_a = fork();

if (child_a == 0) {
    /* Child A code */
  time_t t;
      int i;
      srand((unsigned) time(&t));
      int loop_amount = (rand() % 30);
      for (i = 1; i <= loop_amount ; i++) {
        printf("Child Pid: %d is going to sleep!\n", getpid());
        sleep((rand() % 10));
        printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n",getpid(), getppid());
        
      }
      printf("   *** Child A: %d process is done ***\n",getpid());
      exit(getpid());
} else {
    child_b = fork();

    if (child_b == 0) {
        /* Child B code */
      time_t t;
      int i;
      srand((unsigned) time(&t));
      int loop_amount = (rand() % 30);
      for (i = 1; i <= loop_amount ; i++) {
        printf("Child Pid: %d is going to sleep!\n", getpid());
        sleep((rand() % 10));
        printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n",getpid(), getppid());
        
      }
      printf("   *** Child B: %d process is done ***\n", getpid());
      exit(getpid());
    } else {
        /* Parent Code */

    while ((wpid = wait(&status)) > 0)
    {
        printf("Child Pid: %d has completed.Exit status of was %d (%s)\n", (int)wpid, status,
               (status > 0) ? "accept" : "reject");
    }
      
    }
}
}
