// coding: utf-8

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

volatile uint16_t toene[] = {
	9530,	//0 - c'
	8490,	//1 - d'
	7570,	//2 - e'
	7130,	//3 - f'
	6360,	//4 - g'
	5660,	//5 - a'
	0440,	//6 - h'
	37640,	//7 - c''
	32440,	//8 - d''
	24780,	//9 - e''
	25640,	//10- f''
	21740,	//11- g''
	18420,	//12- a''
	15420,	//13- h''
	13740,	//14- c'''
	11104,	//15- d'''
	4880,	//16- e'''
	7480,	//17- f'''
	5840,	//18- g'''
	4104,	//19- a'''
	2540,	//20- h'''
	1
};

volatile uint8_t tud[] = {
	12, 53,
	3, 42,
	13, 42,
	2, 42,
	18, 42,
	12, 53,
	8, 42,
	16, 42,
	12, 42,
	7, 42,
	16, 53,
	3, 42,
	16, 42,
	12, 42,
	7, 42,
	15, 42,
	3, 42,
	5, 42,
	3, 42,
	21, 10
};

volatile uint8_t data, dauer;


ISR(TIMER2_COMP_vect){
	if (dauer < tud[data+1]){
		dauer++;
	} else {
		data += 2;
		if (data > 24)
			data = 0;
		OCR1A = toene[tud[data]];
		dauer = 0;
	}
}

void init_timer1(void){
	OCR1A = toene[tud[data]];
	TCCR1A |= (1<<COM1A0);
	TCCR1B |= (1<<WGM12)|(1<<CS10);//|(1<<CS10);
}

void init_timer2(void){
	OCR2 = 155;
	TCCR2 |= (1<<WGM21)|(1<<CS22);
	TIMSK |= (1<<OCIE2);
}


void init(void) {
	DDRB |= (1<<PB1);
	DDRB &= ~(1<<PB0);
	PORTB |= (1<<PB0);
	init_timer1();
	init_timer2();
	sei();
	dauer = tud[data+1];
}

int main(void) {
	init();

	while(1) {
		if ((PINB & (1<<PB0))){
			TCCR1A &= ~(1<<COM1A0);
		} else {
			TCCR1A |= (1<<COM1A0);
		}
	}
	return 0;
}

