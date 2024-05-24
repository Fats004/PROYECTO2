* PWM2.c
 *
 * Created: 5/5/2024 10:09:18 PM
 *  Author: Fatima
 */ 

#include "PWM2.h"
#include <avr/io.h>
#include <stdint.h>

void setPWM2fastA(uint8_t invertido, uint8_t modo, uint16_t prescaler){
	DDRB |= (1 << DDB3); //Setear la salida para PWM2 A
	
	if (invertido == 1){
		TCCR2A |= (1 << COM2A1) | (1 << COM2A0); // Setear como invertido o no
	}
	else {
		TCCR2A |= (1 << COM2A1);
	}
	
	if (modo == 1){
		TCCR2A |= (1 << WGM20) | (1 << WGM21); //Elegir uno de los modos FAST disponibles
		TCCR2B |= (1 << WGM22);
	}
	else {
		TCCR2A |= (1 << WGM20) | (1 << WGM21);
	}
	
	switch (prescaler){ //Setear el prescaler elegido
		case 0:
		TCCR2B |= (1 << CS20);
		break;
		case 8:
		TCCR2B |= (1 << CS21);
		break;
		case 32:
		TCCR2B |= (1 << CS20) | (1 << CS21);
		break;
		case 64:
		TCCR2B |= (1 << CS22);
		break;
		case 128:
		TCCR2B |= (1 << CS20) | (1 << CS22);
		break;
		case 256:
		TCCR2B |= (1 << CS21) | (1 << CS22);
		break;
		case 1024:
		TCCR2B |= (1 << CS20) | (1 <<CS21) | (1 << CS22);
		break;
		
		default:
		TCCR2B |= (1 << CS20);
	}
	
}

void updateDutyA2(uint8_t dutycycle){
	OCR2A = dutycycle; //Update el dutycycle con el valor deseado
}

void setPWM2fastB(uint8_t invertido, uint8_t modo, uint16_t prescaler){
	DDRD |= (1 << DDD3); //Setear la salida para PWM2 B
	
	if (invertido == 1){
		TCCR2A |= (1 << COM2B1) | (1 << COM2B0); // Setear como invertido o no
	}
	else {
		TCCR2A |= (1 << COM2B1);
	}
	
	if (modo == 1){
		TCCR2A |= (1 << WGM20) | (1 << WGM21); //Elegir uno de los modos FAST disponibles
		TCCR2B |= (1 << WGM22);
	}
	else {
		TCCR2A |= (1 << WGM20) | (1 << WGM21);
	}
	
	switch (prescaler){ //Setear el prescaler elegido
		case 0:
		TCCR2B |= (1 << CS20);
		break;
		case 8:
		TCCR2B |= (1 << CS21);
		break;
		case 32:
		TCCR2B |= (1 << CS20) | (1 << CS21);
		break;
		case 64:
		TCCR2B |= (1 << CS22);
		break;
		case 128:
		TCCR2B |= (1 << CS20) | (1 << CS22);
		break;
		case 256:
		TCCR2B |= (1 << CS21) | (1 << CS22);
		break;
		case 1024:
		TCCR2B |= (1 << CS20) | (1 <<CS21) | (1 << CS22);
		break;
		
		default:
		TCCR2B |= (1 << CS20);
	}
	
}

void updateDutyB2(uint8_t dutycycle){
	OCR2B = dutycycle; //Update el dutycycle con el valor deseado
}
