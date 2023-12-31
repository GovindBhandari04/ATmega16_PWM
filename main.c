/*
 * PWM.c
 *
 * Created: 8/19/2023 1:37:13 PM
 * Author : Govind
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	TCCR1A |= (1<<WGM10)|(1<<WGM11);
	TCCR1B |= (1<<WGM12);
	TCCR1B &= ~(1<<WGM13);
	TCCR1A |= (1<<COM1A1);
	TCCR1A &= ~(1<<COM1A0);
	TCCR1B |= (1<<CS10)|(1<<CS11);
	TCCR1B &= ~(1<<CS12);
	DDRD |= (1<<DDD5);
	   
    while (1) 
    {
		for(int i=0;i<1023;i++)
		{
			OCR1A = i;
			_delay_ms(1);
        }
		_delay_ms(50);
		
		
		for(int i=1023;i>=0;i++)
		{
			OCR1A = i;
			_delay_ms(1);
		}
		_delay_ms(50);
		
    }
}