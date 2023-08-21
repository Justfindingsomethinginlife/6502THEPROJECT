#include<stdio.h>
#include<stdlib.h>
#include "../pwd/source.h"
#include "../IST/ist.h"

int main(){
	
	uint8_t *stack_256 = (uint8_t*)malloc(sizeof(uint8_t)*256);

	printf("%d",IRX);
	printf("%d",Accumulator);
	Instruction_Decode(0xC8,&PSR,&Accumulator,&IRX,&IRY,&DL,&PCH,&PCL,&PC,stack_256);
	printf("%d",IRX);
	Instruction_Decode(0x8A,&PSR,&Accumulator,&IRX,&IRY,&DL,&PCH,&PCL,&PC,stack_256);
	printf("%d",Accumulator);
}



