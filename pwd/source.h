#ifndef SOURCE_H_INCLUDED
#define SOURCE_H_INCLUDED

#include<stdint.h>

extern uint8_t PSR;
extern uint8_t Accumulator;
extern uint8_t IRX;
extern uint8_t IRY;
extern uint16_t DL;

extern uint8_t PCL;
extern uint8_t PCH;
extern uint16_t PC;

extern int isEmpty(uint8_t *stack,int *pos);
extern int isFull(uint8_t *stack,int *pos,int size);
extern int peek(uint8_t *stack,int pos);
extern int push(uint8_t *stack,int *pos,int size,uint8_t val);
extern int pop(uint8_t *stack,int *pos,int size);

extern int Addr_INC(int *PC);

#endif

