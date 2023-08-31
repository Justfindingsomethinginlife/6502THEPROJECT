#ifndef IST_H
#define IST_H

#include<stdint.h>

extern uint8_t DATA_BUS;
extern uint16_t ADDR_BUS;
extern int BE;
extern int RWB;

extern int isBE(int BE);
extern int RWB_STATUS(int RWB);
extern int ReadDATA(FILE *f);
extern uint8_t Instruction_Decode(uint8_t IST,uint8_t *PSR_1,uint8_t *Accumulator_1,uint8_t *IRX_1,uint8_t *IRY_1,uint16_t *DL_1,uint8_t *PCH_1,uint8_t *PCL_1,uint16_t *PC_1,uint8_t *stack,
int *pos);
extern uint8_t PHA(uint8_t *stack,uint8_t val,int pos,int size);
extern int nop(uint16_t *PC);
extern int INY(uint8_t *IRY);
extern int DEX();
extern int DEY();
extern int TAX();
extern int TAY();
extern int TXA();
extern int TXS();
extern int TSX();


//NOT COMPLETE!

#endif

