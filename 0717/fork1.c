#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
static int glob=6;
char buf[]="a write to stdout\n";

int main(void)
{
	int var;
	pid_t pid;

	var=88;
	if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
		perror("write error");
	printf("befor fork\n");

	if((pid=fork())<0)
		perror("fork error");
	else if(pid==0)
	{
		sleep(2);
		glob++;
		var++;
		printf("child");
		printf("pid=%d, glob=%d, var=%d\n",getpid(),glob,var);
//		sleep(10);	
		


	}
	else
	{	
		sleep(2);
		
		printf("parent");
		printf("pid=%d, glob=%d, var=%d\n",getpid(),glob,var);
	}			
}
