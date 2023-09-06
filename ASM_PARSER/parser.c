#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{

	FILE *fr = fopen("opcode.asm","r");
	FILE *fw = fopen("parsed.txt", "r+");
	size_t MAXLINE;
	char line1[20];
	char * line;
	int linecount =0;
	while(getline(&line,&MAXLINE,fr) != -1)
	{
		//printf("%s",line);
		strncpy(line,line1,MAXLINE);
		printf("%s",line1[10]);
	}

}
