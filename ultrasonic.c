#include "ultrasonic.h"

extern uint8  g_dc_motorFlag;
extern uint8  g_trig_flag ;
extern uint32 g_counter   ;
extern uint8 edge ;

//The Callback function for ISR
void ult_callback(){
    if (edge ==RISING ){
        Icu_setEdgeDetectionType(FALLING);      //set TTCR1B to the FALLING edge detection
        Icu_clearTimerValue();                 // clear Timer1 value to start from 0
        edge = FALLING;
    }
    else {
        Icu_setEdgeDetectionType(RISING);        //set TTCR1B to RISING edge detection
        g_counter = Icu_getInputCaptureValue(); //LOAD ICR IN g_counter
        Icu_clearTimerValue();                 //clear Timer1 value to start from 0
        edge= RISING;
        g_dc_motorFlag=1;  //SETTING DC_FLAG 
        g_trig_flag=1;
    }
}

void ult_init(){
     SET_BIT(DDRD,PD5);      //TRIG PIN AS OUTPUT
    CLEAR_BIT(PORTD,PD5);  //INTIALLY OFF 

    Icu_ConfigType MY_Config = {F_CPU_CLOCK,RISING};  //ICU CONFIGURATION NO PRESCALER,RISING EDDGE
    Icu_init(&MY_Config);           //ICU Intiilization
    Icu_setCallBack(ult_callback);   //SETTING CALL BACK FUNCTION TO ULTRASONIC FUNCTION
}

void ult_trig(){
    SET_BIT(PORTD,PD5);
    _delay_us(15);
    CLEAR_BIT(PORTD,PD5);
}