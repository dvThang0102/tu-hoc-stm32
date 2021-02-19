#include "stm32f10x.h"                  // Device header
#include "GPIO_STM32F10x.h"             // Keil::Device:GPIO

uint16_t i =0;

void Delay_ms(uint32_t);

int main(void)
{
	GPIO_PinConfigure(GPIOC, 13, GPIO_OUT_PUSH_PULL,GPIO_MODE_OUT2MHZ);
	while(1)
	{
		GPIO_PinWrite(GPIOC,13,0);
		Delay_ms(500);
		GPIO_PinWrite(GPIOC,13,1);
		Delay_ms(500);
		i++;
	}
}
void Delay_ms(uint32_t ms)
{
	for(uint32_t i = 0;i<ms; i++)
		for(volatile uint32_t j = 0; j<525; j++);
}