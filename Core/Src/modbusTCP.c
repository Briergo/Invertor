
#include "modbusTCP.h"
#include "modbusGet.h"
#include "modbusRegister.h"
#include "modbusFunc.h"
#include "string.h"
#include "boolean.h"

/* ----------------------- MBAP Header --------------------------------------*/
/*
 *
 * <------------------------ MODBUS TCP/IP ADU(1) ------------------------->
 *              <----------- MODBUS PDU (1') ---------------->
 *  +-----------+---------------+------------------------------------------+
 *  | TID | PID | Length | UID  |Code | Data                               |
 *  +-----------+---------------+------------------------------------------+
 *  |     |     |        |      |
 * (2)   (3)   (4)      (5)    (6)
 *
 * (2)  ... MB_TCP_TID          = 0 (Transaction Identifier - 2 Byte)
 * (3)  ... MB_TCP_PID          = 2 (Protocol Identifier - 2 Byte)
 * (4)  ... MB_TCP_LEN          = 4 (Number of bytes - 2 Byte)
 * (5)  ... MB_TCP_UID          = 6 (Unit Identifier - 1 Byte)
 * (6)  ... MB_TCP_FUNC         = 7 (Modbus Function Code)
 *
 * (1)  ... Modbus TCP/IP Application Data Unit
 * (1') ... Modbus Protocol Data Unit
 */

  
char in_buf[100];
char out_buf[100];

extern node_t* current;
extern node_t* Reg1;

void modbustpc_take_buf(char* payload,unsigned int tot_len)
{
  memset (in_buf, '\0', 100);
  memset (out_buf, '\0', 100);
  memcpy(in_buf, (char *)payload, tot_len);  
}


int mudbustcp_go(char* payload,unsigned int tot_len)
{
  int tid, pid, address, count,len=0,value;
  char func, uid, boole;
  current=Reg1;
  modbustpc_take_buf(payload,tot_len);
  tid=modbustcp_get_tid();
  pid=modbustcp_get_pid();
  uid=modbustcp_get_uid();
  func=modbustcp_get_func();
  address=modbustcp_get_address();
  count=modbustcp_get_count();
  if(uid==MY_ID)
  {
    switch(func)
    {
    case 0x04:
    {
      while(current!=NULL)
      {
        if(current->address==address)
        {
          len=modbustcp_send_answer_fun_0x04(tid,pid,uid,func,address,count);
          return len; 
        }
        else 
          current=current->next;
      }
    }
    break;
    case 0x03:
    {
      while(current!=NULL)
      {
        if(current->address==address)
        {
          len=modbustcp_send_answer_fun_0x04(tid,pid,uid,func,address,count);
          return len; 
        }
        else 
          current=current->next;
      }
    }
    break;
    case 0x05:
    {
      while(current!=NULL)
      {
        if(current->address==address)
        {
          boole=modbustcp_get_boll_value();
          set_bool(boole);
          len=modbustcp_send_answer_fun_0x05(tid,pid,uid,func,address,boole);
          return len; 
        }
        else 
          current=current->next;
      }
    }
    break;
    case 0x01:
    {
      while(current!=NULL)
      {
        if(current->address==address)
        {
          len=modbustcp_send_answer_fun_0x01(tid,pid,uid,func);
          return len; 
        }
        else 
          current=current->next;
      }
    }
    break;
    case 0x06:
    {
      while(current!=NULL)
      { 
        if(current->address==address)
        {
          value=modbustcp_get_value();
          current->value=value;
          modbus_regist_obrab();
          len=modbustcp_send_answer_fun_0x06(tid,pid,uid,func, address,value);
          return len; 
        }
        else 
          current=current->next;
      }
    }
    break;
    }
  } 
  return len; 
}



