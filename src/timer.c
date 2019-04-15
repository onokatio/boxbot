#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include <sys/time.h>
#include <signal.h>
//#define MILLI_SEC 1000

struct itimerval value =  {1, 0, 1, 0};
//struct itimerval value = {0, 500*MILLI_SEC , 0, 500*MILLI_SEC };
struct itimerval ovalue = {0, 0, 0, 0};
void whentime();

int timeinit(){
  if (signal(SIGALRM, whentime) == SIG_ERR) {
    printf("signal set error.");
    return 1;
  }
  setitimer(ITIMER_REAL, &value, &ovalue);
}

void whentime(){

  printf("\033[%d;%dH" ,1,1);
  printf("%d fps\n",fpscounter);
  fpscounter = 0;
  fflush(stdout);
  if (signal(SIGALRM, whentime) == SIG_ERR) {
    printf("signal reset error.");
    return;
  }
  return;
}
