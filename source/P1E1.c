
/**
 * @file    P1E1.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL43Z4.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */
#include "JT_board.h"
#include "key.h"

/* TODO: insert other definitions and declarations here. */


typedef enum
{
	EST_MEF_LED_INICIALIZACION = 0,
	EST_MEF_LED_ON,
	EST_MEF_LED_OFF
}estMefLed_enum;



void mefLed(void)
{
    static estMefLed_enum estMefLed = EST_MEF_LED_INICIALIZACION;

    switch (estMefLed)
    {
        case EST_MEF_LED_INICIALIZACION:
            board_setLed(BOARD_LED_ID_ROJO, BOARD_LED_MSG_OFF);
            estMefLed = EST_MEF_LED_OFF;
            break;

        case EST_MEF_LED_ON:
            if (key_getPressEv(BOARD_SW_ID_1)){
                board_setLed(BOARD_LED_ID_ROJO, BOARD_LED_MSG_OFF);
                estMefLed = EST_MEF_LED_OFF;
            }
            break;
        case EST_MEF_LED_OFF:
            if (key_getPressEv(BOARD_SW_ID_3)){
                board_setLed(BOARD_LED_ID_ROJO, BOARD_LED_MSG_ON);
                estMefLed = EST_MEF_LED_ON;
            }
            break;
    }
}


/*
 * @brief   Main.
 */
int main(void) {

	board_init();


	SysTick_Config(SystemCoreClock / 1000U);

    while(1)
    {
    	mefLed();
    }
    return 0 ;
}

void SysTick_Handler(void)
{
    key_periodicTask1ms();
}


