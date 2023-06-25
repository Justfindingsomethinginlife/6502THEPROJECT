#include<stdio.h>
#include "../pwd/source.h"
#include "../IST/ist.h"

int main(){


	printf("%d",PC);

	Instruction_Decode(0xEA,&PSR,&Accumulator,&IRX,&IRY,&DL,&PCH,&PCL,&PC);

	printf("%d",PC);

}


