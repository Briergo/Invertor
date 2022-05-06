#include "boolean.h"
#include "main.h"
#include "modbusRegister.h"

extern node_t* current;

void set_bool(char boole)
{
  char boolname;
  current->bool_value=boole;
  boolname=current->bool_name;
  switch(boolname)
    {
    case LED1:
    {
      if(boole)
        HAL_GPIO_WritePin(LD1_GPIO_Port,LD1_Pin,GPIO_PIN_SET);
      else
        HAL_GPIO_WritePin(LD1_GPIO_Port,LD1_Pin,GPIO_PIN_RESET);
    }
    break;
    case LED2:
    {
      if(boole)
        HAL_GPIO_WritePin(LD2_GPIO_Port,LD2_Pin,GPIO_PIN_SET);
      else
        HAL_GPIO_WritePin(LD2_GPIO_Port,LD2_Pin,GPIO_PIN_RESET);
    }
    break;
    case LED3:
    {
      if(boole)
        HAL_GPIO_WritePin(LD3_GPIO_Port,LD3_Pin,GPIO_PIN_SET);
      else
        HAL_GPIO_WritePin(LD3_GPIO_Port,LD3_Pin,GPIO_PIN_RESET);
    }
    break;
    }
}