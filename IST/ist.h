#include<stdint.h>

extern uint8_t DATA_BUS;
extern uint16_t ADDR_BUS;
extern int BE;
extern int RWB;

extern int isBE(int BE);
extern int RWB_STATUS(int RWB);
extern int ReadDATA(FILE *f);
//NOT COMPLETE!

