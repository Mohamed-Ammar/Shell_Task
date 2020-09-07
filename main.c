#include "dc_motor.h"
#include "ultrasonic.h"

//global variables 
uint8  g_dc_motorFlag = 0;
uint8  g_trig_flag =1;
uint32 g_dist      =0;     //distance
uint32 g_counter   =0;
uint8 edge = RISING;



int main(void){
    sei();           //SET GLOBAL INTERRUPT
    dc_motorInit(); // DC MOTOR Initilization
    ult_init();

    while(1){
        if (g_dc_motorFlag==1){
            g_dist =(uint32)(g_counter*34300)/(uint32)(2000000);  //distance in cm (time*speed of sound / 2)
            if (g_dist>=165){       //165 is the 50% of the sensor, There is a +3 error in simulation change occur after 168
                dc_motor(START);
            }
            else{
                dc_motor(REVERSE);
            }
            g_dc_motorFlag=0;    //clearing DC_motor flag
        }
        
        if(g_trig_flag==1){       //triggering
        ult_trig();
        }
    _delay_ms(500);
    }
}