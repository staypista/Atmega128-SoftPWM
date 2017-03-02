/*
 * pwm.c
 *
 * Created: 2016. 09. 13. 9:01:45
 * Author : Nagy Zsolt
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
void init();
uint8_t i=0;

ISR(TIMER0_COMP_vect){
	PORTD&=~(1<<7);
}

ISR(TIMER0_OVF_vect){
	PORTD|=(1<<7);	
}

int main(void){
    init();
    for(;;){
	}
}

void init(){
	DDRC|=(1<<PD7);
	DDRE|=(1<<PE3)|(1<<PE2);
	DDRD|=(1<<7);
	TCCR0|=(1<<CS00);
	TIMSK|=(1<<OCIE0)|(1<<TOIE0);
	OCR0=250;
	sei();
}

