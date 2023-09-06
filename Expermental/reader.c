#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../pwd/source.h"
#include "../IST/ist.h"

int Instruction(char * path,uint8_t *stack,int *pos)
{
	
	FILE* fp = fopen("main.txt","r");
	char * linecmp = "NOP";
	char line[10];
	while(fgets(line,10,fp) != NULL)
	{
		if(strstr(line,"NOP"))
		{
			Instruction_Decode(0xEA,&PSR,&Accumulator,&IRX,&IRY,&DL,&PCH,&PCL,&PC,stack,pos);
		}

	//	if(line[strlen(line)-1] != '\n') printf("\n");
	}

	fclose(fp);
}


/***
int main()
{
	FILE* fp = fopen("main.txt","r");
	char * linecmp = "NOP";
	char line[10];
	while(fgets(line,10,fp) != NULL)
	{
		if(strstr(line,"NOP"))
		{

		}

	//	if(line[strlen(line)-1] != '\n') printf("\n");
	}

	fclose(fp);
}
***/
