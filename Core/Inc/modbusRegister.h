#ifndef __MODBUSREGISTER_H
#define __MODBUSREGISTER_H


typedef struct node 
{
  struct node* next;
  int value;
  int address;
  char bool_value;
  char bool_name;
}
node_t;

void modbus_register_create(void);
void modbus_regist_obrab(void);


#endif /* MODBUSREGISTER */