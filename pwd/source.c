#include<stdio.h>
#include<stdlib.h>

#include"source.h"

//------------------------------------------------------------------------------------------------

//							CONSTANT



//------------------------------------------------------------------------------------------------

int STACK_ADDR_MAX = 0x1FF;
int STACK_ADDR_MIN = 0x100;
//------------------------------------------------------------------------------------------------

//                                                     STACK

int init(uint8_t *stack,int pos,int size){

	stack = (uint8_t*)malloc(size*sizeof(uint8_t));
	if(stack == NULL){
		//printf("STACK NOT INITIATED");
		return 1;
	}
	else{
		//printf("STACK INITIATED");
		return -1;
	}
}

int isEmpty(uint8_t *stack){
	if(stack == NULL){return 1;}
	else{return 0;}
}

int isFull(uint8_t *stack,int pos,int size){
	if(isEmpty(stack)){return -1;}

	if(pos = size){
		return 0;
	}
	else{
		return 1;
	}
}

int peek(uint8_t *stack,int pos){
	return stack[pos];
}


//----------------------------------------------------------------------------------------------------


uint16_t initialize(uint8_t PCL,uint8_t PCH,uint16_t PC){
	PC = (PCH<<8)|PCL;
	return PC;
}






int main(){
	int pos=0;
	int size = 256;
	uint8_t *STACK_256 = (uint8_t*)malloc(256*sizeof(uint8_t));
	
	for (int j = 0; j < 2; ++j) {
		pos++;
		STACK_256[j] = j + 1;
        }
	for (int k = 0; k < pos; ++k) {

        	printf("%d, ", STACK_256[k]);

    	}

	printf("%d",peek(STACK_256,1));

        PC = initialize(PCL,PCH,PC);
	
	return 0;
}
