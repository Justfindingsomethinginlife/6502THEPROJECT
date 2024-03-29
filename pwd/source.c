#include<stdio.h>
#include<stdlib.h>

#include"source.h"

//------------------------------------------------------------------------------------------------
//						   DATA_REGISTER

uint8_t PSR = 0x00 | 0x20 ;
uint8_t Accumulator = 0x00;
uint8_t IRX = 0x00;
uint8_t IRY = 0x00;
uint16_t DL= 0x00;

uint8_t PCL=0xfc;
uint8_t PCH=0xff;
uint16_t PC=0x00;
//------------------------------------------------------------------------------------------------

#define STACK_ADDR_MAX = 0x1FF;
#define STACK_ADDR_MIN = 0x100;
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

int isEmpty(uint8_t *stack,int *pos){
	if(*pos == -1){return 1;}
	else{return 0;}
}

int isFull(uint8_t *stack,int *pos,int size){


	if(*pos == size){
		return 1;
	}
	else{
		return 0;
	}
}

int peek(uint8_t *stack,int pos){
	return stack[pos];
}

int push(uint8_t *stack,int *pos,int size,uint8_t val){
	
	if(isFull(stack,pos,size)){
		return 2;
	}
	else{
		stack[(*pos)+1] = val;
	}

	(*pos)++;

}

int pop(uint8_t *stack,int *pos,int size){
	if(isEmpty(stack,pos)){
		return -1;
	}
	else{
		(*pos)--;
	}
}


//----------------------------------------------------------------------------------------------------
//						Address Manipulation

uint16_t initialize(uint8_t PCL,uint8_t PCH,uint16_t PC){
	PC = (PCH<<8)|PCL;
	return PC;
}
	
int Addr_INC(int *PC){
	(*PC)++;
}







