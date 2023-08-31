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
}




uint8_t Instruction_Decode(uint8_t IST,uint8_t *PSR_1,uint8_t *Accumulator_1,uint8_t *IRX_1,uint8_t *IRY_1,uint16_t *DL_1,uint8_t *PCH_1,uint8_t *PCL_1,uint16_t *PC_1 ,uint8_t *stack,
int *pos){	
	switch(IST){

		case 0xEA: //NOP
			(*PC_1)++;
			break;

		case 0xE8: //INY
			(*IRY_1)++;
			(*PC_1)++;
			break;

		case 0xC8: //INX
			(*IRX_1)++;
			(*PC_1)++;
			break;
		
		case 0xCA: //DEX
			(*IRX_1)--;
			(*PC_1)++;
			break;

		case 0x88: //DEY
			(*IRY_1)--;
			(*PC_1)++;
			break;

		case 0xAA: //TAX
			(*IRX_1) = (*Accumulator_1);
			(*Accumulator_1) = 0;
			(*PC_1)++;
			break;

		case 0xA8: //TAY
			(*IRY_1) = (*Accumulator_1);
			(*Accumulator_1)  = 0;
			(*PC_1)++;
			break;

		case 0x8A: //TXA
			(*Accumulator_1) = (*IRX_1);
			(*IRX_1) = 0;
			(*PC_1)++;
			break;

		case 0x98: //TYA
			(*Accumulator_1) = (*IRY_1);
			(*IRY_1) = 0;
			(*PC_1)++;
			break;
		
		case 0x48: //PHA
			if(*pos == 255)
			{
				printf("STACK OVERFLOW");
				break;				
			}
			(*pos)++;
			stack[*pos] = (*Accumulator_1);
			(*PC_1)++;
			break;

		case 0x68: //PLA
			if(*pos == -1)
			{
				printf("STACK EMPTY");
				break;
			}
			(*Accumulator_1) = stack[*pos];
			(*pos)--;
			(*PC_1)++;



		case 0xBA: //TSX
			if(*pos == -1)
			{
				printf("STACK EMPTY");
				break;
			}
			(*IRX_1) = (*pos);
			(*PC_1)++;
			break;



	}	
}





