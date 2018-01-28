#include "inc/tm4c123gh6pm.h"
void PortF_Output(uint32_t data){ // write PF3-PF1 outputs
  GPIO_PORTF_DATA_R = data;      
}