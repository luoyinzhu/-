#include "stm32f10x.h"                  // Device header
#include "led.h"
int main(void)
{
	

	Led_t Led[3];//��������led�ṹ�壬���ڱ���
	Led_int(&Led[0], GPIOA, GPIO_Pin_1);  //��ʼ��
	LED_Operation (&Led[0], Open);  //����
	
	
	


		while (1)
		{
			
		}
}
