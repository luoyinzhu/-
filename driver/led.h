#ifndef _led__h_
#define _led__h_


/*���ڱ���led�豸��port��pin*/
typedef struct {
	
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;	
}Led_t;

typedef enum {Close = 0, Open =!Close} Operation;

int Led_int(Led_t* led, GPIO_TypeDef* port, uint16_t pin); 
int LED_Operation (Led_t* led, Operation operate);

#endif
