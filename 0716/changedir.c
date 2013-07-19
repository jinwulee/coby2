#include <unistd.h>
#include <stdio.h>

#define PATH_MAX 1024

int main(void)
{
	char path[PATH_MAX+1];
	if(chdir("/tmp")<0)
			perror("error chdir");
	else
	{
		if(getcwd(path,PATH_MAX)==NULL)
			perror("error getcwd");
		else
			printf("현재폴더는 %s\n",path);

	}
}
