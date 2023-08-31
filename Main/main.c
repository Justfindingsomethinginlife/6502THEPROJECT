#include<stdio.h>
#include<stdlib.h>
#include "../pwd/source.h"
#include "../IST/ist.h"

int main(){
	
	int pos=-1;
	uint8_t *stack_256 = (uint8_t*)malloc(sizeof(uint8_t)*256);
	printf("%d",IRX);
	printf("%d",Accumulator);
	Instruction_Decode(0xC8,&PSR,&Accumulator,&IRX,&IRY,&DL,&PCH,&PCL,&PC,stack_256,&pos);
	printf("%d",IRX);
	Instruction_Decode(0x8A,&PSR,&Accumulator,&IRX,&IRY,&DL,&PCH,&PCL,&PC,stack_256,&pos);
	Instruction_Decode(0x48,&PSR,&Accumulator,&IRX,&IRY,&DL,&PCH,&PCL,&PC,stack_256,&pos);
	Instruction_Decode(0xBA,&PSR,&Accumulator,&IRX,&IRY,&DL,&PCH,&PCL,&PC,stack_256,&pos);
	printf("%d",IRX);
	printf("%d",stack_256[pos]);
	printf("%d",Accumulator);
	printf("\n");
}



