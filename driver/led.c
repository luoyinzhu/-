#include "stm32f10x.h" 
#include "led.h"

#define __SetBit_(GPIOx, GPIO_Pin)  GPIO_SetBits(GPIOx, GPIO_Pin)    
#define __ResetBit_(GPIOx, GPIO_Pin)  GPIO_ResetBits(GPIOx, GPIO_Pin)



/******************************************************************************
 * @brief ��ʼ������    
 *
 * @param[p]  led   :  ָ��ṹ��Led_t
 * @param[in]  port  :  GPIOx
 * @param[in]  pin   :  GPIO_Pin_x
 *
 * @return     ��
 *
 ******************************************************************************/
int Led_int(Led_t* led, GPIO_TypeDef* port, uint16_t pin) 
{
	
	/*ʹ��ʱ��*/
	if(port==GPIOA) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	if(port==GPIOB) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	if(port==GPIOC) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	if(port==GPIOD) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
		
    /*���ų�ʼ��*/	
	led->GPIOx = port;
	led->GPIO_Pin = pin;
	GPIO_InitTypeDef InitType;	
	InitType.GPIO_Mode =  GPIO_Mode_Out_PP;
	InitType.GPIO_Pin = pin;
	InitType.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(port, &InitType);
	
	return 1;
}



 /******************************************************************************
 * @brief ���������������߹أ�    
 *
 * @param[p]  led   :  ָ��ṹ��Led_t
 * @param[Operation]  operate:  Open:���ƣ�Close���ص�
 *
 * @return   1ִ�гɹ�������ʧ��
 *
 ******************************************************************************/
int LED_Operation (Led_t* led, Operation operate)
{
	if(!led) 
	  return -1; //ִ�е�return�ͻ����������ˣ�������break��������ִ������������

	if (operate == Open)
	  __SetBit_(led->GPIOx, led->GPIO_Pin);//�õ��˵�һ�γ�ʼ��ʱ������豸�ṹ����
	
	if (operate == Close)
	  __ResetBit_(led->GPIOx, led->GPIO_Pin);
	
	return 1;
}




