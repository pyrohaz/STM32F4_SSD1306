#include <GFX.h>

volatile uint32_t MSec = 0;

void Delay(uint32_t D){
	uint32_t MSS = MSec;
	while((MSec-MSS)< D) asm volatile("nop");
}

void SysTick_Handler(void){
	MSec++;
}

int main(void)
{
	SysTick_Config(SystemCoreClock/1000);
	SSD1306_InitSetup();
	PStr("Hello", 0, 0, 0, 0);
	PScrn();

    while(1)
    {
    }
}
