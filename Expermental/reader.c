#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *fp;
	char * line[20] = NULL;
	size_t len =0;
	ssize_t read;

	fp = fopen("main.txt","r");
	if(fp == NULL) exit(EXIT_FAILURE);

	while((read = getline(&line,&len,fp)) != -1){
		printf("%s",line);
	}

	fclose(fp);
	if(line)
		free(line);
	exit(EXIT_SUCCESS);	
}
