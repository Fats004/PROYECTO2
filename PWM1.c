/*
 * PWM1.c
 *
 * Created: 5/5/2024 10:08:39 PM
 *  Author: Fatima
 */ 

#include "PWM1.h"
#include <avr/io.h>
#include <stdint.h>

void setPWM1fastA(uint8_t invertido, uint8_t modo, uint16_t prescaler){
	
	DDRB |= (1 << DDB1);
	
	TCCR1A = 0;
	TCCR1B = 0;
	
	if (invertido == 1){ // sETEAR SI ES INVERIDO O NO
		TCCR1A |= (1 << COM1A1) | (1 << COM1A0);
	}
	else {
		TCCR1A |= (1 << COM1A1);
	}
	
	switch (modo){ //Setear el modo FAST deseado
		case 0:
		TCCR1A |= (1 << WGM10);
		TCCR1B |= (1 << WGM12);
		break;
		case 1:
		TCCR1A |= (1 << WGM11);
		TCCR1B |= (1 << WGM12);
		break;
		case 2:
		TCCR1A |= (1 << WGM10) | (1 << WGM11);
		TCCR1B |= (1 << WGM12);
		break;
		case 3:
		TCCR1A |= (1 << WGM10);
		TCCR1B |= (1 << WGM12) | (1 << WGM13);
		break;
		case 4:
		TCCR1A |= (1 << WGM10) | (1 << WGM11);
		TCCR1B |= (1 << WGM12) | (1 << WGM13);
		break;
		
		default:
		TCCR1A |= (1 << WGM10);
		TCCR1B |= (1 << WGM12);
	}
	
	switch (prescaler){ // Setear el prescaler deseado
		case 0:
		TCCR1B |= (1 << CS10);
		break;
		case 8:
		TCCR1B |= (1 << CS11);
		break;
		case 64:
		TCCR1B |= (1 << CS10) | (1 << CS11);
		break;
		case 256:
		TCCR1B |= (1 << CS12);
		break;
		case 1024:
		TCCR1B |= (1 << CS10) | (1 << CS12);
		break;
		
		default:
		TCCR1B |= (1 << CS10);
	}
	
}


void updateDutyA1(uint8_t dutycycle){
	OCR1A = dutycycle; // Actlizar el dutycycle
}


void setPWM1fastB(uint8_t invertido, uint8_t modo, uint16_t prescaler){
	
	DDRB |= (1 << DDB2);
	
	if (invertido == 1){ // sETEAR SI ES INVERIDO O NO
		TCCR1A |= (1 << COM1B1) | (1 << COM1B0);
	}
	else {
		TCCR1A |= (1 << COM1B1);
	}
	
	switch (modo){ //Setear el modo FAST deseado
		case 0:
		TCCR1A |= (1 << WGM10);
		TCCR1B |= (1 << WGM12);
		break;
		case 1:
		TCCR1A |= (1 << WGM11);
		TCCR1B |= (1 << WGM12);
		break;
		case 2:
		TCCR1A |= (1 << WGM10) | (1 << WGM11);
		TCCR1B |= (1 << WGM12);
		break;
		case 3:
		TCCR1A |= (1 << WGM10);
		TCCR1B |= (1 << WGM12) | (1 << WGM13);
		break;
		case 4:
		TCCR1A |= (1 << WGM10) | (1 << WGM11);
		TCCR1B |= (1 << WGM12) | (1 << WGM13);
		break;
		
		default:
		TCCR1A |= (1 << WGM10);
		TCCR1B |= (1 << WGM12);
	}
	
	switch (prescaler){ // Setear el prescaler deseado
		case 0:
		TCCR1B |= (1 << CS10);
		break;
		case 8:
		TCCR1B |= (1 << CS11);
		break;
		case 64:
		TCCR1B |= (1 << CS10) | (1 << CS11);
		break;
		case 256:
		TCCR1B |= (1 << CS12);
		break;
		case 1024:
		TCCR1B |= (1 << CS10) | (1 << CS12);
		break;
		
		default:
		TCCR1B |= (1 << CS10);
	}
	
}


void updateDutyB1(uint8_t dutycycle){
	OCR1B = dutycycle; // Actlizar el dutycycle
}
