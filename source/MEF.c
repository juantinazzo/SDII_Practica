/*
 * MEF.c
 *
 *  Created on: 24 mar. 2022
 *      Author: juant
 */

#include "MEF.h"
#include "JT_board.h"
extern bool SW1_click, SW3_click;

void mef1(void) {
	static estMef_enum estMEF1 = EST_MEF_START;

	switch (estMEF1) {
	case EST_MEF_START:
		if (SW1_click)
			estMEF1 = EST_MEF_P1;
		break;

	case EST_MEF_P1:
		if (SW1_click)
			estMEF1 = EST_MEF_P2;
		if (SW3_click)
			estMEF1 = EST_MEF_START;
		break;
	case EST_MEF_P2:
		if (SW3_click) {
			board_setLed(BOARD_LED_ID_ROJO, BOARD_LED_MSG_TOGGLE);
			estMEF1=EST_MEF_START;
		}
		break;
	}
}

void mef2(void) {
	static estMef_enum estMEF2 = EST_MEF_START;

	switch (estMEF2) {
	case EST_MEF_START:
		if (SW3_click)
			estMEF2 = EST_MEF_P1;
		break;

	case EST_MEF_P1:
		if (SW1_click)
			estMEF2 = EST_MEF_P2;
		break;
	case EST_MEF_P2:
		if (SW1_click)
			estMEF2 = EST_MEF_START;
		if (SW3_click) {
			board_setLed(BOARD_LED_ID_VERDE, BOARD_LED_MSG_TOGGLE);
			estMEF2=EST_MEF_START;
		}
		break;
	}
}
