#ifndef _ULTRASONIC_H_
#define _ULTRASONIC_H_

#include "common_macros.h"
#include "micro_config.h"
#include "std_types.h"
#include "icu.h"

void ult_init();     //function to intialize the ultrasonic sensor
void ult_trig();     //function for the triggering
void ult_callback(); //the call back function

#endif