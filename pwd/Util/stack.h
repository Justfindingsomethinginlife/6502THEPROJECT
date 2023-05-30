#include<stdint.h>

#ifndef STACK_UTIL
#define STACK_UTIL
	

	extern int init(uint8_t *stack,int size);
	extern int isFull(uint8_t *stack,uint8_t pos,int size);
	extern int isEmpty(uint8_t *stack,uint8_t pos,int size);
	extern int peek(uint8_t *stack,uint8_t pos);
	extern int push(uint8_t *stack,uint8_t pos);
	extern int pop(uint8_t *stack,uint8_t pos);
	extern int delete(uint8_t *stack);
	
#endif
