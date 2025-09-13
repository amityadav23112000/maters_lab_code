 #include <signal.h>  
#include <stdio.h>  
#include <unistd.h>  
#include<stdlib.h>

/*
Default SIGCHLD is “ignored”; your handler overrides that and reaps children immediately so they don’t become zombies.
Your handler calls wait() only once per signal delivery.
If multiple children exit at nearly the same time, the kernel may deliver SIGCHLD multiple times (or coalesce events)
. Your handler will eventually be called again until all terminated children are reaped.
*/
void handler(int sig)  
{  
 pid_t pid;  
 pid = wait(NULL);  
 printf("\t\tChild %d exited.\n", pid);  
 signal(SIGCHLD, handler);  
}  
int main()  
{  
 int i;  
 signal(SIGCHLD, handler);  
 for(i=0;i<3;i++)  
 switch(fork())  
 { 
   
  case 0:  
  printf("\tChild created %d\n", getpid());  
  exit(0); 

 }  
 sleep(2);  
 return 0;  
}
 
