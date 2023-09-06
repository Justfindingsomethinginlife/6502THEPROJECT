#include<stdio.h>
#include<stdlib.h>
#include "../pwd/source.h"
#include "../IST/ist.h"
#include "../Expermental/reader.h"

int main(){
	
	int pos=0x01FF;
	uint8_t *MEM = (uint8_t*)malloc(65535*sizeof(uint8_t));
	MEM[0xFFFC] = 0x00;
	MEM[0xFFFD] = 0x20;
	MEM[0x2000] = 0xA0;
	MEM[0x2001] = 0x00;
	MEM[0x2002] = 0xA0;
	MEM[0x2003] = 0x02;
	MEM[0x2004] = 0xEA;
	MEM[0x2005] = 0xEA;

	PC = 0xFFFC;
	PCL = MEM[PC];
	PC++;
	PCH = MEM[PC];
	PC = PCH<<8 | PCL;
	for(int i=PC;i<0x2010;i++)
	{	
		printf("%x",PC);printf(" ");
		printf("%x",i);printf(" ");printf("%x",IRY);printf(" ");printf("%x",PSR);
		Instruction_Decode(MEM[i],&PSR,&Accumulator,&IRX,&IRY,&DL,&PCH,&PCL,&PC,MEM,&pos,&i);
		printf("\n");	
	}

//	printf("%x",*(MEM + 0x01FF));printf("\n");
	
	
		



	free(MEM);
}



