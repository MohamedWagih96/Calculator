#include "inc/tm4c123gh6pm.h"
uint32_t PortF_Input(void){     
  return (GPIO_PORTF_DATA_R&0x11);  // read PF4,PF0 inputs
}