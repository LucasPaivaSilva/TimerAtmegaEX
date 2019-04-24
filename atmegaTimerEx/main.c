/*
 * atmegaTimerEx.c
 *
 * Created: 4/23/2019 4:31:23 PM
 * Author : Lucas
 */ 
#include "def_principais.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#define LED PB5
//------------------------------------------------------------------------
ISR(TIMER1_COMPA_vect) //interrupção do TC1
{
	cpl_bit(PORTB,LED);
}
//------------------------------------------------------------------------
int main()
{
	DDRB = 0b00100000;//somente pino do LED como saída
	PORTB = 0b11011111;//apaga LED e habilita pull-ups nos pinos não utilizados
	
	TCNT1 = 0;
	OCR1A = 15624;
	TCCR1A = (1<<COM1A0);
	TCCR1B = (1<<CS10) | (1<<CS12) | (1<<WGM12);//TC1 com prescaler de 1024
	TIMSK1 = (1<<OCIE1A); //habilita a interrupção do T1
	sei(); //habilita a chave de interrupção global
	while(1)
	{
	
	}
}