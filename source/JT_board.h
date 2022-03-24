#ifndef JT_BOARD_H
#define JT_BOARD_H

#include <MKL43Z4.h>
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "fsl_clock.h"
#include "pin_mux.h"

typedef enum
{
    BOARD_LED_ID_ROJO = 0,
    BOARD_LED_ID_VERDE,
    BOARD_LED_ID_TOTAL
}board_ledId_enum;

typedef enum
{
    BOARD_SW_ID_1 = 0,
    BOARD_SW_ID_3,
    BOARD_SW_ID_TOTAL
}board_swId_enum;

typedef struct
{
    PORT_Type *port;
    GPIO_Type *gpio;
    uint32_t pin;
}board_gpioInfo_type;

typedef enum
{
    BOARD_LED_MSG_OFF = 0,
    BOARD_LED_MSG_ON,
    BOARD_LED_MSG_TOGGLE
}board_ledMsg_enum;

static const board_gpioInfo_type board_gpioLeds[] =
{
    {PORTE, GPIOE, 31},     /* LED ROJO */
    {PORTD, GPIOD, 5},      /* LED VERDE */
};

static const board_gpioInfo_type board_gpioSw[] =
{
    {PORTC, GPIOA, 4},      /* SW1 */
    {PORTC, GPIOC, 3},     /* SW3 */
};

void board_setLed(board_ledId_enum id, board_ledMsg_enum msg);
bool board_getSw(board_swId_enum id);
void board_init(void);

#endif
