#include "modbusRegister.h"
#include "stdlib.h"
#include "boolean.h"
#include "sinus.h"

extern unsigned char amplitud; 
extern unsigned char counter; 
extern unsigned char flag_counter;
extern unsigned int freg_signal;
extern unsigned char flag_freq;

node_t* current=NULL;


//Create Register
node_t* Reg1=NULL;
node_t* Reg2=NULL;
node_t* Reg3=NULL;
node_t* Reg4=NULL;
node_t* Reg5=NULL;
node_t* Reg6=NULL;

void modbus_register_create(void)
{
   //Create Register 1
   Reg1=malloc(sizeof(node_t));
   Reg1->next=malloc(sizeof(node_t));
   Reg1->value=amplitud;
   Reg1->address=0;
   Reg1->bool_value=0;
   //Create Register 2
   Reg2=Reg1->next;
   Reg2->next=malloc(sizeof(node_t));
   Reg2->value=freg_signal;
   Reg2->address=1;
   Reg2->bool_value=0;
   //Create Register 3
   Reg3=Reg2->next;
   Reg3->next=malloc(sizeof(node_t));
   Reg3->value=555;
   Reg3->address=2;
   Reg3->bool_value=0;
   //Create Register 4
   Reg4=Reg3->next;
   Reg4->next=malloc(sizeof(node_t));
   Reg4->value=0;
   Reg4->address=3;
   Reg4->bool_value=0;
   Reg4->bool_name=LED1;
   //Create Register 5
   Reg5=Reg4->next;
   Reg5->next=malloc(sizeof(node_t));
   Reg5->value=0;
   Reg5->address=13;
   Reg5->bool_value=0;
   Reg5->bool_name=LED2;
   //Create Register 6
   Reg6=Reg5->next;
   Reg6->next=NULL;
   Reg6->value=0;
   Reg6->address=30;
   Reg6->bool_value=0;
   Reg6->bool_name=LED3;
   current=Reg1;
}

void modbus_regist_obrab(void)
{
  if(Reg1->value>100)
    Reg1->value=100;
  if(Reg1->value<0)
    Reg1->value=0;
  amplitud=Reg1->value;
  if(counter<amplitud)
     flag_counter=PLUS;
  else if(counter>amplitud)
     flag_counter=MINUS;
  if(Reg2->value!=freg_signal)
  {
    freg_signal=Reg2->value;
    flag_freq=1;
  }
}