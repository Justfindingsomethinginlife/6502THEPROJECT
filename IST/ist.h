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

extern uint8_t PHA(uint8_t *stack,uint8_t val,int pos,int size);
extern int nop(uint16_t *PC);
extern int DEX();
extern int DEY();
extern int TAX();
extern int TAY();
extern int TXA();
extern int TXS();
extern int TSX();


//NOT COMPLETE!

#endif

