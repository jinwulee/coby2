#include <stdio.h>
#include <stdlib.h>

void main()
{
	int c, number=0;
	char op;
	FILE *fp;

	if((fp=fopen("test.txt","r"))==NULL)
	{
		perror("FILE open error");
		exit(-1);


	}
	while(!feof(fp))
	{
		while((c=fgetc(fp))!=EOF && isdigit(c))
			number=10*number+c-'0';
		if(c=='\n')
			continue;

		fprintf(stdout,"operand=>%d\n",number);
		number=0;

		if(c!=EOF)
		{
			ungetc(c,fp);
			op=fgetc(fp);
			fprintf(stdout,"poerator=>%c\n",op);
		}

	}
	fclose(fp);

}
