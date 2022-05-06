#include "modbusRegister.h"
#include "modbusFunc.h"
#include "boolean.h"
#include "stdlib.h"

extern char out_buf[100];


extern node_t* current;

int modbustcp_send_answer_fun_0x04(int tid, int pid, char uid, char func, int address, int counter)
{
  int len=0,len_next=0, len_data, value;
  unsigned char HiByteValue=0, LoByteValue=0,k=0;
  out_buf[MB_TCP_TID]=tid>>8;
  out_buf[MB_TCP_TID+1]=tid;
  out_buf[MB_TCP_PID]=pid>>8;
  out_buf[MB_TCP_PID+1]=pid;
  len_next=counter*2+3;
  out_buf[MB_TCP_LEN]=len_next>>8;
  out_buf[MB_TCP_LEN+1]=len_next;
  out_buf[MB_TCP_UID]=uid;
  out_buf[MB_TCP_FUNC]=func;
  len_data=counter*2;
  out_buf[MB_TCP_FUNC+1]=len_data;
  while(current!=NULL && k<counter)
  {
    value=current->value;
    HiByteValue=value>>8;
    LoByteValue=value;
    out_buf[MB_TCP_Data+k*2]=HiByteValue;
    out_buf[MB_TCP_Data+k*2+1]=LoByteValue;
    current=current->next;
    k++;
  }
  len=counter*2+9; 
  return  len;
}

int modbustcp_send_answer_fun_0x05(int tid, int pid, char uid, char func, int address,char boole)
{
  out_buf[MB_TCP_TID]=tid>>8;
  out_buf[MB_TCP_TID+1]=tid;
  out_buf[MB_TCP_PID]=pid>>8;
  out_buf[MB_TCP_PID+1]=pid;
  out_buf[MB_TCP_LEN]=0x00;
  out_buf[MB_TCP_LEN+1]=0x06;
  out_buf[MB_TCP_UID]=uid;
  out_buf[MB_TCP_FUNC]=func;
  out_buf[MB_TCP_ADDRESS]=address>>8;
  out_buf[MB_TCP_ADDRESS+1]=address;
  if(boole)
  {
    out_buf[MB_TCP_Take_Data]=0xFF;
    out_buf[MB_TCP_Take_Data+1]=0x00;
  }
  else
  {
    out_buf[MB_TCP_Take_Data]=0x00;
    out_buf[MB_TCP_Take_Data+1]=0x00;
  }
  return  12;
}

int modbustcp_send_answer_fun_0x01(int tid, int pid, char uid, char func)
{
  int len=0,len_next=0, len_data;
  out_buf[MB_TCP_TID]=tid>>8;
  out_buf[MB_TCP_TID+1]=tid;
  out_buf[MB_TCP_PID]=pid>>8;
  out_buf[MB_TCP_PID+1]=pid;
  len_next=4;
  out_buf[MB_TCP_LEN]=len_next>>8;
  out_buf[MB_TCP_LEN+1]=len_next;
  out_buf[MB_TCP_UID]=uid;
  out_buf[MB_TCP_FUNC]=func;
  len_data=1;
  out_buf[MB_TCP_FUNC+1]=len_data;
  out_buf[MB_TCP_Data]=current->bool_value;
  len=10; 
  return  len;
}

int modbustcp_send_answer_fun_0x06(int tid, int pid, char uid, char func, int address,int value)
{
  out_buf[MB_TCP_TID]=tid>>8;
  out_buf[MB_TCP_TID+1]=tid;
  out_buf[MB_TCP_PID]=pid>>8;
  out_buf[MB_TCP_PID+1]=pid;
  out_buf[MB_TCP_LEN]=0x00;
  out_buf[MB_TCP_LEN+1]=0x06;
  out_buf[MB_TCP_UID]=uid;
  out_buf[MB_TCP_FUNC]=func;
  out_buf[MB_TCP_ADDRESS]=address>>8;
  out_buf[MB_TCP_ADDRESS+1]=address;
  out_buf[MB_TCP_Take_Data]=value>>8;
  out_buf[MB_TCP_Take_Data+1]=value;
  return  12;
}