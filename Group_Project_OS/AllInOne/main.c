/*
* Name: Dhir Talati
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <math.h>

void test1(int);
void test2(int);
void test3(int);
void test4(int);
void test5(int);
void QS(int L[], int min, int max);

int main(int argc, char* argv[]) {

  int stat;
  if (argc != 2) {
      printf("Run program by ./prog1 (number of child 1 - 25)\n");
      return 1;
  } 
  int PROCESS_NUM = atoi(argv[1]);
  if(PROCESS_NUM > 25){
      printf("Max child process is 25\n");
      return 1;
  }
  int *pids;
  pids = (int*)malloc(sizeof(int)* PROCESS_NUM);
  if (pids == NULL) { 
      printf("Memory allocation error\n"); 
      exit(-1); 
  }


  printf("Parent pid is %d\n", getpid());

  int i;
  for(i = 0; i < PROCESS_NUM; i++){
    pids[i] = fork();
    if(pids[i] == -1){
      printf("Error Creating Processes\n");
      return 1;
    }
  
    if(pids[i] == 0){
      //child process

      int j = i + 1;
      printf("Started child %d with pid %d\n", j, getpid()); 
      // test1(getpid());
      exit(0);
    }
    
  }

 
  for(i = 0; i < PROCESS_NUM; i++){

    //-------------------------Part A--------------------------------
      /* 
      * Since Part A is basically creating a single child, you can
      * run the program by ./prog1 1, simply give just 1 for child 
      * process argument
      */
    //---------------------------------------------------------------

    //-------------------------Part B--------------------------------
      /* 
      * Since part B is craeting double children, you run the program
      * by ./prog1 2, simply give 2 for child process argument
      */
    //---------------------------------------------------------------

    //-------------------------Part C--------------------------------
      /* 
      * In part C, you can give any number from 1 to 25 to test the
      * multiple childern process
      */
    //---------------------------------------------------------------

    //-------------------------Part D--------------------------------
      /* 
      * Part D is identifying the childern in oder it was created.
      * This is already implemented from part A.
      * Try run any test from Part A to C.
      */
    //---------------------------------------------------------------

    //-------------------------Part E--------------------------------
      /* 
      * Uncomment the following code to test Part E
      */
      test1(pids[i]);

    //---------------------------------------------------------------

    //-------------------------Part F--------------------------------
      /* 
      * Uncomment the following codes to test Part F
      */
      // test1(pids[i]);
      // test2(pids[i+1]);
      // test3(pids[i+2]); 
      // test4(pids[i+3]);
      // test5(pids[i+4]);
      // test1(pids[i+5]);
      // i=PROCESS_NUM;
    //---------------------------------------------------------------
   

    wait(NULL);

    if(pids[i] == 0){
      free(pids);
    }
  }
  for(i = 0; i < PROCESS_NUM; i++){
        int st = waitpid(pids[i], &stat, 0);
    if( st != 0){
      int j = i + 1;
      printf("Child %d (PID %d) finished.\n", j, pids[i]);
    }
  }

  return 0;
}

void test1(int pid){
  int i;
  printf("Running program test1 in process %d\n", pid);
  for (i = 0; i < 5; i++)
    printf("T1: i %d, i^2 %d\n", i, i*i);
}

void test2(int pid){

  printf("Running program test2 in process %d\n", (int)pid);
  printf("T2: sqrt of PID %d is %.2lf\n", (int)getpid(), sqrt((double)pid));
  
}

void test3(int pid){
  pid_t _pid = pid;
  printf("Running program test3 in process %d\n", (int)_pid);
  if ((int)_pid % 2)
    printf("T3: PID %d is odd\n", (int)_pid);
  else
    printf("T3: PID %d is even\n", (int)_pid);
}

void test4(int pids){
  int x = (int)pids;
  int n = 0;
  printf("Running program test4 in process %d\n", x);
  while (x > 0) {
    n++;
    x = x / 10;
  }
  printf("T4: PID %d has %d digits\n", (int)getpid(), n);
}

void test5(int pids){
  int list[] = {5, 1, 3, 10, 7, 9, 4, 2, 8, 6};
  int i;

  printf("Running program test5 in process %d\n", (int)pids);
  QS(list, 0, 9);

  printf("T5: Final list = ");
  for (i = 0; i < 10; i++)
  printf("%d ", list[i]);
  printf("\n");
}

void QS(int L[], int min, int max) {
  int i, j;
  int P;
  int temp;
  printf("T5: QS L[%d-%d]\n", min, max);

  P = L[min];
  i = max;
  j = min + 1;

  while (j < i) {
    while (L[i] > P) 
      i--;
    while ((j < i) && (L[j] < P))
      j++;

    if (j == i) {
      L[min] = L[i];
      L[i] = P;
    }
    else {
      temp = L[i];
      L[i] = L[j];
      L[j] = temp;
    }
  }

  if (min + 1 < i)
    QS(L, min, i - 1);
  if (i + 1 < max)
    QS(L, i + 1, max);
}
