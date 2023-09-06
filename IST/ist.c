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
int *pos,int *iterator){	
	switch(IST){

		case 0xEA: //NOP
			(*PC_1)++;
			break;

		case 0xC8: //INY
			(*IRY_1)++;
			(*PC_1)++;
			if(*IRY_1 != 0) (*PSR_1) = (*PSR_1)&0x7D;
			if(*IRY_1 == 0) (*PSR_1) = ((*PSR_1)|0x2)&0x7F;	
			if(*IRY_1 & 0x80 != 0) (*PSR_1)=((*PSR_1)|0x80)&0x7D;
			break;

		case 0xE8: //INX	
			(*IRX_1)++;
			(*PC_1)++;
			if(*IRX_1 != 0) (*PSR_1) = (*PSR_1)&0x7D;
			if(*IRX_1 == 0) (*PSR_1) = ((*PSR_1)|0x2)&0x7F;	
			if(*IRX_1 & 0x80 != 0) (*PSR_1)=((*PSR_1)|0x80)&0x7D;			
			break;
		
		case 0xCA: //DEX
			(*IRX_1)--;
			(*PC_1)++;
			if(*IRX_1 != 0) (*PSR_1) = (*PSR_1)&0xFD;
			if(*IRX_1 == 0) (*PSR_1) = ((*PSR_1)|0x2)&0x7F;	
			if(*IRX_1 & 0x80 != 0) (*PSR_1)=((*PSR_1)|0x80)&0x7D;	
			break;

		case 0x88: //DEY
			(*IRY_1)--;
			(*PC_1)++;
			if(*IRY_1 != 0) (*PSR_1) = (*PSR_1)&0xFD;
			if(*IRY_1 == 0) (*PSR_1) = ((*PSR_1)|0x2)&0x7F;	
			if(*IRY_1 & 0x80 != 0) (*PSR_1)=((*PSR_1)|0x80)&0x7D;
			break;

		case 0xA9: //LDA
			(*PC_1)++;
			(*Accumulator_1) = *(stack + (*PC_1));
			(*PC_1)++;
			(*iterator) = (*PC_1);
			if(*Accumulator_1 != 0) (*PSR_1) = (*PSR_1)&0xFD;
			if(*Accumulator_1 == 0) (*PSR_1) = ((*PSR_1)|0x2)&0x7F;	
			if(*Accumulator_1 & 0x80 != 0) (*PSR_1)=((*PSR_1)|0x80)&0x7D;
			break;

		case 0xA2: //LDX
			(*PC_1)++;
			(*IRX_1) = *(stack + (*PC_1));
			(*PC_1)++;
			(*iterator) = (*PC_1);
			if(*IRX_1 != 0) (*PSR_1) = (*PSR_1)&0xFD;
			if(*IRX_1 == 0) (*PSR_1) = ((*PSR_1)|0x2)&0x7F;	
			if(*IRX_1 & 0x80 != 0) (*PSR_1)=((*PSR_1)|0x80)&0x7D;				
			break;

		case 0xA0: //LDY
			(*PC_1)++;
			(*IRY_1) = *(stack + (*PC_1));
			(*PC_1)++;
			(*iterator) = (*PC_1)-1;
			if(*IRY_1 != 0){(*PSR_1) = (*PSR_1)&0xFD;}
			if(*IRY_1 == 0){(*PSR_1) = (((*PSR_1)|0x2)&0x7F);}
			if(*IRY_1 & 0x80 != 0){(*PSR_1)=((*PSR_1)|0x80)&0x7D;}
			break;

		case 0xAA: //TAX
			(*IRX_1) = (*Accumulator_1);
			(*Accumulator_1) = 0;
			(*PC_1)++;
			if(*IRX_1 != 0) (*PSR_1) = (*PSR_1)&0xFD;
			if(*IRX_1 == 0) (*PSR_1) = ((*PSR_1)|0x2)&0x7F;	
			if(*IRX_1 & 0x80 != 0) ((*PSR_1)=(*PSR_1)|0x80)&0x7D;				
			break;

		case 0xA8: //TAY
			(*IRY_1) = (*Accumulator_1);
			(*Accumulator_1)  = 0;
			(*PC_1)++;
			if(*IRY_1 != 0) (*PSR_1) = (*PSR_1)&0xFD;
			if(*IRY_1 == 0) (*PSR_1) = ((*PSR_1)|0x2)&0x7F;	
			if(*IRY_1 & 0x80 != 0) (*PSR_1)=((*PSR_1)|0x80)&0x7D;
			break;

		case 0x8A: //TXA
			(*Accumulator_1) = (*IRX_1);
			(*IRX_1) = 0;
			(*PC_1)++;
			if(*Accumulator_1 != 0) (*PSR_1) = (*PSR_1)&0xFD;
			if(*Accumulator_1 == 0) (*PSR_1) = ((*PSR_1)|0x2)&0x7F;	
			if(*Accumulator_1 & 0x80 != 0) (*PSR_1)=((*PSR_1)|0x80)&0x7D;
			break;

		case 0x98: //TYA
			(*Accumulator_1) = (*IRY_1);
			(*IRY_1) = 0;
			(*PC_1)++;
			if(*Accumulator_1 != 0) (*PSR_1) = (*PSR_1)&0xFD;
			if(*Accumulator_1 == 0) (*PSR_1) = ((*PSR_1)|0x2)&0x7F;	
			if(*Accumulator_1 & 0x80 != 0) (*PSR_1)=((*PSR_1)|0x80)&0x7D;
			break;
	
		case 0x20: //JSR
			if(*pos-0x01FF > 255)
			{
				printf("STACK OVERFLOW");
				break;
			}
			*(stack + (*pos)) = ((*PC_1 + 3)&0xFF00) / 256;
			//printf("%x",(*PC_1)&0xFF00);			
			(*pos)--;
			*(stack + (*pos)) =  (*PC_1 + 3)&0x00FF;
			(*pos)--;
			(*PC_1)++;
			//printf("%x",(*PC_1));printf("\n");
			(*PCL_1) = *(stack+(*PC_1));
			(*PC_1)++;
			(*PCH_1) = *(stack+(*PC_1));
			(*PC_1) = (*PCH_1) << 8| (*PCL_1); 
			(*iterator) = (*PC_1)-1;
			break;

		case 0x60: //RTS
			if(*pos - 0x01FF == 0)
			{
				printf("STACK_EMPTY");
				break;
			}
			//printf(" ");printf("%x", *(stack + (*pos)+1));
			//printf(" ");printf("%x", *(stack + (*pos) + 2));
			(*PCL_1) = *(stack + (*pos)+1);
			(*pos)++;
			//printf(" ");printf("%x",*PCH_1);printf(" ");
			(*PCH_1) = *(stack + (*pos)+1);
			(*pos)++;
			//printf("%x",*PCL_1);
			(*PC_1) = (*PCH_1)<<8 | (*PCL_1);
			(*iterator) == (*PC_1)-1;
			break;



		case 0x48: //PHA
			
			if(*pos-0x100 > 255)
			{
				printf("STACK OVERFLOW");
				break;				
			}
			*(stack+ (*pos)) = (*Accumulator_1);
			(*pos)--;
			(*PC_1)++;
			break;

		case 0x68: //PLA
			if(*pos - 0x01FF == 0)
			{
				printf("STACK EMPTY");
				break;
			}
			(*Accumulator_1) = *(stack+(*pos)+1);
			(*pos)++;
			(*PC_1)++;
			if(*Accumulator_1 != 0) (*PSR_1) = ((*PSR_1)&0xFD);
			if(*Accumulator_1 == 0) (*PSR_1) = ((*PSR_1)|0x2)&0x7F;	
			if(*Accumulator_1 & 0x80 != 0) ((*PSR_1)=(*PSR_1)|0x80)&0x7D;
			break;



		case 0xBA: //TSX
			(*IRX_1) = (*pos);
			(*PC_1)++;
			break;



	}	
}





