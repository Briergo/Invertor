#ifndef __MODBUSTCP_H
#define __MODBUSTCP_H


void modbustpc_take_buf(char* payload,unsigned int tot_len);
int mudbustcp_go(char* payload, unsigned int tot_len);

#endif /* MODBUSTCP */