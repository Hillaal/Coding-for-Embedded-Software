

#ifndef INC_DEVICE_H_
#define INC_DEVICE_H_

#include "device_cfg.h"

void (*functions_ptr[MAX_NUM_CLIENTS])(float);
float data;


void Get_Data(void);
void notify(void);
unsigned char subscribe(void (*ptr)(float));
void unsubscribe(unsigned char function_ID);

#endif /* INC_DEVICE_H_ */
