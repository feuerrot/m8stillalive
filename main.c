// coding: utf-8
#include <avr/io.h>
#include <avr/interrupt.h>

#define LAENGE 200

#define NGA fck // Ganzer Fuckup
#define NHA 255 // Halbe Note
#define NVI 127 // Viertelnote
#define NAC 63  // Achtelnote
#define NSE 31  // Sechzehntelnote

#define PAUSE	10
#define C1		30577
#define CIS1	28861
#define D1		27241
#define DIS1	25712
#define E1		24269
#define F1		22907
#define FIS1	21621
#define G1		20407
#define GIS1	19262
#define A1		18181
#define AIS1	17160
#define H1		16197
#define C2		15288
#define CIS2	14430
#define D2		13620
#define DIS2	12855
#define E2		12134
#define F2		11453
#define FIS2	10810
#define G2		10203
#define GIS2	9630
#define A2		9090
#define AIS2	8580
#define H2		8098
#define C3		7644

volatile uint16_t tud[] = {
	G2,		NAC,
	FIS2,	NAC,
	E2,		NAC,
	E2,		NAC,
	FIS2,	NAC,
	PAUSE,	NHA,
	PAUSE,	NHA,
	A1,		NAC,
	G2,		NAC,
	FIS2,	NAC,
	E2,		NAC,
	E2,		NAC,
	FIS2,	NAC,
	PAUSE,	NVI,
	D2, 	NVI,
	E2,		NAC,
	A1,		NAC,
	A1,		NAC,
	PAUSE,	NHA,
	PAUSE,	NHA,
	A1,		NAC,
	E2,		NVI,
	FIS2,	NAC,
	G2,		NAC,
	G2,		NAC,
	E2,		NAC,
	CIS2,	NAC,
	CIS2,	NAC,
	D2,		NVI,
	D2,		NAC,
	E2,		NVI,
	A1,		NAC,
	A1,		NAC,
	A1,		NAC,
	FIS2,	NVI,
	PAUSE,	NHA,
	PAUSE,	NHA,
	G2,		NAC,
	FIS2,	NAC,
	E2,		NAC,
	E2,		NAC,
	FIS2,	NAC,
	PAUSE,	NHA,
	PAUSE,	NHA,
	A1,		NAC,
	G2,		NAC,
	FIS2,	NAC,
	E2,		NAC,
	E2,		NAC,
	PAUSE,	NVI,
	FIS2,	NAC,
	D2,		NAC,
	PAUSE,	NVI,
	E2,		NAC,
	A1,		NAC,
	A1,		NAC,
	PAUSE,	NHA,
	PAUSE,	NVI,
	E2,		NVI,
	FIS2,	NAC,
	G2,		NAC,
	G2,		NAC,
	E2,		NAC,
	CIS2,	NAC,
	CIS2,	NAC,
	D2,		NAC,
	E2,		NAC,
	PAUSE,	NAC,
	A1,		NAC,
	D2,		NAC,
	E2,		NAC,
	F2,		NAC,
	E2,		NAC,
	D2,		NAC,
	C2, 	NAC,
	PAUSE,	NVI,
	A1,		NAC,
	AIS1,	NAC,
	C2,		NVI,
	F2,		NVI,
	E2,		NAC,
	D2,		NAC,
	D2,		NAC,
	C2,		NAC,
	D2,		NAC,
	C2,		NAC,
	C2,		NVI,
	C2,		NVI,
	A1,		NAC,
	AIS1,	NAC,
	C2,		NVI,
	F2,		NVI,
	G2,		NAC,
	F2,		NAC,
	E2,		NAC,
	D2,		NAC,
	D2,		NAC,
	E2,		NAC,
	F2,		NVI,
	F2,		NVI,
	G2,		NAC,
	A2,		NAC,
	AIS2,	NAC,
	AIS2,	NAC,
	A2,		NVI,
	G2,		NVI,
	F2,		NAC,
	G2,		NAC,
	A2,		NAC,
	A2,		NAC,
	G2,		NVI,
	F2,		NVI,
	D2,		NAC,
	C2,		NAC,
	D2,		NAC,
	F2,		NAC,
	F2,		NAC,
	E2,		NAC,
	E2,		NAC,
	E2,		NAC,
	FIS2,	NAC,
	FIS2,	NAC,
	FIS2,	NAC,
	PAUSE,	NHA,
	PAUSE,	NHA,
	A1,		NAC,
	G2,		NAC,
	FIS2,	NAC,
	E2,		NAC,
	E2,		NAC,
	E2,		NSE,
	FIS2,	NAC,
	FIS2,	NSE,
	PAUSE,	NHA,
	PAUSE,	NVI,
	G2,		NAC,
	FIS2,	NAC,
	E2,		NAC,
	E2,		NAC,
	E2,		NVI,
	FIS2,	NAC,
	D2,		NAC,
	D2,		NAC,
	E2,		NVI,
	A1,		NAC,
	A1,		NAC,
	PAUSE,	NAC,
	PAUSE,	NVI,
	PAUSE,	NHA,
	E2,		NVI,
	FIS2,	NAC,
	G2,		NAC,
	G2,		NVI,
	E2,		NVI,
	CIS2,	NVI,
	D2,		NAC,
	E2,		NAC,
	E2,		NAC,
	A1,		NAC,
	A1,		NAC,
	A1,		NAC,
	FIS2,	NAC,
	PAUSE,	NAC,
	PAUSE,	NVI,
	A1, 	NAC,
	G2,		NAC,
	FIS2,	NAC,
	E2,		NAC,
	E2,		NAC,
	FIS2,	NAC,
	PAUSE,	NAC,
	PAUSE,	NVI,
	PAUSE,	NHA,
	A1,		NAC,
	G2,		NAC,
	FIS2,	NAC,
	E2,		NAC,
	E2,		NAC,
	PAUSE,	NVI,
	FIS2,	NAC,
	D2, 	NAC,
	PAUSE,	NVI,
	E2,		NAC,
	A1,		NAC,
	A1,		NAC,
	PAUSE,	NVI,
	PAUSE,	NHA,
	E2,		NVI,
	FIS2,	NAC,
	G2,		NAC,
	G2,		NVI,
	E2,		NVI,
	CIS2,	NVI,
	D2,		NAC,
	E2,		NAC,
	PAUSE,	NAC,
	A1,		NAC,
	D2,		NAC,
	E2,		NAC,
	F2,		NAC,
	E2,		NAC,
	D2,		NAC,
	C2,		NAC,
	PAUSE,	NVI,
	A1,		NAC,
	AIS1,	NAC,
	C2,		NVI,
	F2,		NVI,
	E2,		NAC,
	D2,		NAC,
	D2,		NAC,
	C2,		NAC,
	D2,		NAC,
	C2,		NAC,
	C2,		NVI,
	C2,		NVI,
	A1,		NAC,
	AIS1,	NAC,
	C2,		NVI,
	F2,		NVI,
	G2,		NAC,
	F2,		NAC,
#if 0
	E2,		NAC,
	D2,		NAC,
	D2,		NAC,
	E2,		NAC,
	F2,		NVI,
	F2,		NVI,
	G2,		NAC,
	A2,		NAC,
	AIS2,	NAC,
	AIS2,	NAC,
	A2,		NVI,
	G2,		NVI,
	F2,		NAC,
	G2,		NAC,
	A2,		NAC,
	A2,		NAC,
	G2,		NAC,
	F2,		NAC,
	F2,		NVI,
	D2,		NAC,
	C2,		NAC,
	D2,		NAC,
	F2,		NAC,
	F2,		NAC,
	E2,		NAC,
	E2,		NAC,
	E2,		NAC,
	FIS2,	NAC,
	FIS2,	NAC,
	FIS2,	NAC,
	PAUSE,	NVI,
	PAUSE,	NHA
#endif
};

volatile uint8_t data;
volatile uint8_t dauer;


ISR(TIMER2_COMP_vect){
	if (dauer < tud[data+1]){
		dauer++;
	} else {
		data += 2;
		if (data > LAENGE*2)
			data = 0;
		OCR1A = tud[data];
		dauer = 0;
	}
}

void init_timer1(void){
	OCR1A = tud[data];
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

