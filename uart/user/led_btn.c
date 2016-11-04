#include "osapi.h"
#include "user_interface.h"
#include "gpio.h"
#define BTN_PIN 0//GPIO0
static uint32_t led_value = 0;
void (*pressed_callback)(void) = NULL;
void key_intr_handler(void *args)
{
	uint32_t gpio_status = GPIO_REG_READ(GPIO_STATUS_ADDRESS);
	if(gpio_status & BIT(BTN_PIN)){
		if(pressed_callback)
		pressed_callback();
	}
	GPIO_REG_WRITE(GPIO_STATUS_W1TC_ADDRESS, BIT(BTN_PIN));//XOA TRANG THAI INTERRUPT
} 