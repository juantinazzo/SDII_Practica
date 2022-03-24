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
#include "MEF.h"

/* TODO: insert other definitions and declarations here. */

bool SW1_click,SW3_click;

/*
 * @brief   Main.
 */
int main(void) {

	board_init();

	SysTick_Config(SystemCoreClock / 1000U);

	board_setLed(BOARD_LED_ID_ROJO, BOARD_LED_MSG_ON);
	board_setLed(BOARD_LED_ID_VERDE, BOARD_LED_MSG_ON);
	while (1) {
		SW1_click=key_getReleasedEv(BOARD_SW_ID_1);
		SW3_click=key_getReleasedEv(BOARD_SW_ID_3);
		mef1();
		mef2();
	}
	return 0;
}

void SysTick_Handler(void) {
	key_periodicTask1ms();
}

