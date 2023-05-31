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

uint8_t PHA(uint8_t *stack,uint8_t val,int pos,int size){
	if(stack == NULL){return 0;}

	if( val < 0 || val > 255){
		return -1;
	}
	else{
		isFull(stack,pos,size);	
	}

}

uint8_t Instruction_Decode(uint8_t IST){
	
}


