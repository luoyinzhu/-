#include "stm32f10x.h"                  // Device header
#include "led.h"
int main(void)
{
	

	Led_t Led[3];//创建三个led结构体，用于保存
	Led_int(&Led[0], GPIOA, GPIO_Pin_1);  //初始化
	LED_Operation (&Led[0], Open);  //开灯
	
	
	


		while (1)
		{
			
		}
}
