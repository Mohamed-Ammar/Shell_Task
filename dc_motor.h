#ifndef _DC_MOTOR_H_
#define _DC_MOTOR_H_

#include"micro_config.h"
#include"std_types.h"
#include"common_macros.h"

typedef enum {                  //three states of the motor
    STOP,START,REVERSE
};

void dc_motorInit();           //motor initilization
void dc_motor(uint8 state);    //motor functionality

#endif