// coding: utf-8
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

#define NGA fck // Ganzer Fuckup
#define NHA 255 // Halbe Note
#define NVI 127 // Viertelnote
#define NAC 63  // Achtelnote
#define NSE 31  // Sechzehntelnote

volatile uint16_t toene[] = {
	10,		//  0 - Zu hoher Ton -> Pause
	30577,	//  1 - c'
	28861,	//  2 - cis'
	27241,	//  3 - d'
	25712,	//  4 - dis'
	24269,	//  5 - e'
	22907,	//  6 - f'
	21621,	//  7 - fis'
	20407,	//  8 - g'
	19262,	//  9 - gis'
	18181,	// 10 - a'
	17160,	// 11 - ais'
	16197,	// 12 - h'
	15288,	// 13 - c''
	14430,	// 14 - cis''
	13620,	// 15 - d''
	12855,	// 16 - dis''
	12134,	// 17 - e''
	11453,	// 18 - f''
	10810,	// 19 - fis''
	10203,	// 20 - g''
	9630,	// 21 - gis''
	9090,	// 22 - a''
	8580,	// 23 - ais''
	8098,	// 24 - h''
	7644	// 25 - c'''
};

volatile uint8_t tud[] = {
	17, NVI,
	16, NVI,
	11, NVI,
	5,  NVI
};

volatile uint8_t data, dauer;


ISR(TIMER2_COMP_vect){
	if (dauer < tud[data+1]){
		dauer++;
	} else {
		data += 2;
		if (data > 8)
			data = 0;
		OCR1A = toene[tud[data]];
		dauer = 0;
	}
}

void init_timer1(void){
	OCR1A = toene[tud[data]];
	TCCR1A |= (1<<COM1A0);
	TCCR1B |= (1<<WGM12)|(1<<CS10);
}

void init_timer2(void){
	OCR2 = 60;
	TCCR2 |= (1<<WGM21)|(1<<CS22)|(1<<CS21)|(1<<CS20);
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
		if (PINB & (1<<PB0)){
			TCCR1A &= ~(1<<COM1A0);
		} else {
			TCCR1A |= (1<<COM1A0);
		}
	}
	return 0;
}

