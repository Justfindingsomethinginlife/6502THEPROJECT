#include<stdio.h>
#include"ist.h"
#include"../pwd/source.h"

int isBE(int BE){
	if(BE == 1){
		return 1;

	}
	else{
		return 0;
	}
}

int RWB_STATUS(int RWB){
	if(RWB==1){
		return 1;
	}
	else{
		return 0;
	}
}

int ReadDATA(FILE *f){
	return 1;
}

int nop(uint16_t *PC){
	(*PC)++;
	return 1;
}

uint8_t Instruction_Decode(uint8_t IST,uint8_t *PSR,uint8_t *Accumulator,uint8_t *IRX,uint8_t *IRY,uint16_t *DL,uint8_t *PCH,uint8_t *PCL,uint16_t *PC){
	
	switch(IST){

		case 0xEA:
			nop(PC);
			break;

	}	
}


