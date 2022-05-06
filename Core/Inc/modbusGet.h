#ifndef __MODBUSGET_H
#define __MODBUSGET_H


int modbustcp_get_tid(void);
int modbustcp_get_pid(void);
int modbustcp_get_len(void);
char modbustcp_get_uid(void);
char modbustcp_get_func(void);
int modbustcp_get_address(void);
int modbustcp_get_count(void);
char modbustcp_get_boll_value(void);
int modbustcp_get_value(void);

#endif /* MODBUSGET */