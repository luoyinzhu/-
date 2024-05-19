#include "stm32f10x.h" 
#include "led.h"

#define __SetBit_(GPIOx, GPIO_Pin)  GPIO_SetBits(GPIOx, GPIO_Pin)    
#define __ResetBit_(GPIOx, GPIO_Pin)  GPIO_ResetBits(GPIOx, GPIO_Pin)



/******************************************************************************
 * @brief 初始化引脚    
 *
 * @param[p]  led   :  指向结构体Led_t
 * @param[in]  port  :  GPIOx
 * @param[in]  pin   :  GPIO_Pin_x
 *
 * @return     无
 *
 ******************************************************************************/
int Led_int(Led_t* led, GPIO_TypeDef* port, uint16_t pin) 
{
	
	/*使能时钟*/
	if(port==GPIOA) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	if(port==GPIOB) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	if(port==GPIOC) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	if(port==GPIOD) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
		
    /*引脚初始化*/	
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
 * @brief 动作函数（开或者关）    
 *
 * @param[p]  led   :  指向结构体Led_t
 * @param[Operation]  operate:  Open:开灯，Close：关灯
 *
 * @return   1执行成功，其余失败
 *
 ******************************************************************************/
int LED_Operation (Led_t* led, Operation operate)
{
	if(!led) 
	  return -1; //执行到return就会跳出函数了，类似于break，不会再执行下面的语句了

	if (operate == Open)
	  __SetBit_(led->GPIOx, led->GPIO_Pin);//用到了第一次初始化时保存的设备结构体了
	
	if (operate == Close)
	  __ResetBit_(led->GPIOx, led->GPIO_Pin);
	
	return 1;
}




