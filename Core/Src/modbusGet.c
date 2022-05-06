#include "modbusFunc.h"
#include "modbusGet.h"

extern char in_buf[100];

//The Function returns the Transaction ID
int modbustcp_get_tid(void)
{
  int tid = in_buf[MB_TCP_TID] << 8U;
  tid |= in_buf[MB_TCP_TID + 1];
  return tid;
}

//The Function returns the Protocol ID
int modbustcp_get_pid(void)
{
  int pid = in_buf[MB_TCP_PID] << 8U;
  pid |= in_buf[MB_TCP_PID + 1];
  return pid;
}
//The Function returns the Length
int modbustcp_get_len(void)
{
  int len = in_buf[MB_TCP_LEN] << 8U;
  len |= in_buf[MB_TCP_LEN + 1]+6;
  return len;
}
//The Function returns the Device address
char modbustcp_get_uid(void)
{
  char uid = in_buf[MB_TCP_UID];
  return uid;
}
//The Function returns the Functional code
char modbustcp_get_func(void)
{
  char func = in_buf[MB_TCP_FUNC];
  return func;
}
//The Function returns the Register Address
int modbustcp_get_address(void)
{
  int address = in_buf[MB_TCP_ADDRESS] << 8U;
  address |= in_buf[MB_TCP_ADDRESS + 1];
  return address;
}
//The Function returns the Number of Registers
int modbustcp_get_count(void)
{
  int count = in_buf[MB_TCP_COUNT] << 8U;
  count |= in_buf[MB_TCP_COUNT + 1];
  return count;
}

//The Function returns 
char modbustcp_get_boll_value(void)
{
  unsigned char boll = in_buf[MB_TCP_Take_Data];
  if(boll)
    return 1;
  else
    return 0;
}

//The Function returns Value
int modbustcp_get_value(void)
{
  int value = in_buf[MB_TCP_Take_Data] << 8U;
  value |= in_buf[MB_TCP_Take_Data + 1];
  return value;
}