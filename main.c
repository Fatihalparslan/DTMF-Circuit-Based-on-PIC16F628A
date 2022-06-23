

#include <16f628A.h>   
#include <stdbool.h>
#FUSES NOWDT                    //No Watch Dog Timer
#FUSES INTRC_IO                 //Internal RC Osc, no CLKOUT
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOMCLR
#use DELAY(int=4MHz)

#define StD pin_b0
#define Q1 pin_b4
#define Q2 pin_b3
#define Q3 pin_b2
#define Q4 pin_b1



 int number;
 
 int sifre[4]={0,0,0,0};

int counter=0;
void main ()
{
set_tris_a(0x00);    
set_tris_b(0xff);    
while(input(StD));

   while(TRUE)
   {
   
  if(input(StD)){
  number=0;

while(input(StD));

   if(input(Q1)){
   
number=number+1;
   }
   if(input(Q2)){
number=number+2;
   }
   if(input(Q3)){
number=number+4;
   }
   if(input(Q4)){
number=number+8;
   }
  sifre[counter]=number;
  counter++;
 if(counter>=4)
 {
 

counter=0;
if((sifre[0]==11)&&(sifre[1]==1)&&(sifre[2]==2)&&(sifre[3]==3)){
output_high(pin_a2);
  }
 if((sifre[0]==11)&&(sifre[1]==3)&&(sifre[2]==2)&&(sifre[3]==1)){
 output_low(pin_a2); 
  }
  sifre[0]=0;
  sifre[1]=0;
  sifre[2]=0;
  sifre[3]=0;
 }
   }

}
}


