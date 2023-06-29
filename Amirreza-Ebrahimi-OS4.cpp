#include<iostream>
#include <sys/types.h> /* pid_t */
#include <unistd.h>  /* _exit, fork */
#include <stdlib.h>  /* exit */
#include <errno.h>   /* errno */
#include<cmath>//for sin()
#include <cstdlib>

#define f(x) 10*abs(sin(0.25*x))
using namespace std;
int j;
int i;
int main(void)
{
   float lower, upper, integration=0.0, stepSize, k;
   int i, subInterval;
   cout<<"Enter lower limit of integration: ";
   cin>>lower;
   cout<<"Enter upper limit of integration: ";
   cin>>upper;
   cout<<"Enter number of sub intervals: ";
   cin>>subInterval;
   stepSize = (upper - lower)/subInterval;//10

   /* Finding Integration Value */
   integration = f(lower) + f(upper);
   pid_t  pid;


   pid = fork();

   if (pid == -1)
   {

      cout<< "can't fork, error \n";
      exit(EXIT_FAILURE);
   }
   else if (pid == 0)
   {
      /* Child process:
       * When fork() returns 0, we are in
       * the child process.
       */
      
      for (j = 1; j <10; j++)
      {
         k = lower + i*stepSize;
         integration = integration + 2 * (f(k));
         cout<<"Childe:"<<j+1<<integration<<endl;
         sleep(1);
      }
      _exit(0);  /* Note that we do not use exit() */
   }
   else
   {
      /* When fork() returns a positive number, we are in the parent process
       * (the fork return value is the PID of the newly created child process)
       * Again we count up to ten.
       */
      
      for (i = 1; i <10; i++)
      {
         
         cout<<"Parent: "<<i+1<<integration<<endl;
         sleep(1);
      }
      	integration = integration * stepSize/2;
	cout<<"Final is "<<integration<<endl;
      exit(0);
   }
   return 0;
}
