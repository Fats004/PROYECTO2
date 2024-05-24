//*******************************************************************************************************************************************
// Universidad del Valle de Guatemala
// IE2023 Programación de Microcontroladores
// main.c
// Proyecto: PROYECTO2
// Hardware: ATMEGA328P
// Created: 5/5/2024
// Author : Fatima Urrutia
//********************************************************************************************************************************************

//********************************************************************************************************************************************
// Librerias
//********************************************************************************************************************************************

# define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <util/delay.h>
#include <avr/eeprom.h>

#include "ADC/ADC.h"
#include "PWM1/PWM1.h"
#include "PWM2/PWM2.h"
#include "PWM0/PWM0.h"

//********************************************************************************************************************************************
// Variables Globales
//********************************************************************************************************************************************

uint8_t POT = 0;
uint8_t POT1 = 0;
uint8_t POT2 = 0;
uint8_t POT3 = 0;
uint8_t POT4 = 0;
uint8_t* address = 0;
uint8_t i = 0;

uint8_t A = 0;
uint8_t B = 0;
uint8_t C = 0;
uint8_t D = 0;

uint8_t num3 = 0;
uint8_t num2 = 0;
uint8_t num1 = 0;
uint8_t cont = 0;

uint8_t sum = 0;
uint8_t sum2 = 0;
uint8_t sum3 = 0;
uint8_t sum4 = 0;

volatile char recibido;

uint8_t modo = 0;
uint8_t modoUART = 0;

void setup(void); 
void setpinchange(void);
void initUART(void);

//********************************************************************************************************************************************
// Main
//********************************************************************************************************************************************

int main(void)
{	
	setup();
	
    while (1) 
    {
		switch (modo){
			case 0:
				//PORTD &= ~(1 << PORTD4);
				//PORTD |= (1 << PORTD7);
				
				ADCSRA |= (1 << ADSC); // Activar la conversion del ADC
				
				//updateDutyA0((POT2/6) + 5); // Actualizar el valor de parpados derechos
				//updateDutyB0((POT1/6) + 5);
				
				updateDutyA1((POT2/15) + 13); // Actualizar el valor de parpados izquierdos
				updateDutyB1((POT1/15) + 16);
				
				updateDutyA2((POT3/9)+ 12); // Actualizar el valor de los lados
				
				updateDutyB2((POT4/11)+ 16);
				
				_delay_ms(4);
				break;
			
			case 1:
				//PORTD &= ~(1 << PORTD7);
				//PORTD |= (1 << PORTD2);
				
				ADCSRA |= (1 << ADSC); // Activar la conversion del ADC
				
				//updateDutyA0(POT2/); // Actualizar el valor de parpados derechos
				//updateDutyB0(POT1/6);
				
				updateDutyA1((POT2/15) + 13); // Actualizar el valor de parpados izquierdos
				updateDutyB1((POT1/15) + 16);
				
				updateDutyA2((POT3/9)+ 12); // Actualizar el valor de los lados
				
				updateDutyB2((POT4/8)+ 16);
				
				_delay_ms(4);
				break;
				
			case 2:
				//PORTD &= ~(1 << PORTD2);
				//PORTD |= (1 << PORTD4);
				
				//updateDutyA0(B/6); // Actualizar el valor de parpados derechos
				//updateDutyB0(A/6);
				
				updateDutyA1((B/15) + 13); // Actualizar el valor de parpados izquierdos
				updateDutyB1((A/15) + 16);
				
				updateDutyA2((C/9)+ 12); // Actualizar el valor de los lados
				
				updateDutyB2((D/8)+ 16);
				
				_delay_ms(4);
				
				break;
				
			case 3:
				//PORTD |= (1 << PORTD4) | (1 << PORTD7);
				
				
				switch (modoUART){
					case 0:
						/*updateDutyA1(sum/6); // Actualizar el valor de parpados izquierdos
						updateDutyB1(sum/6);
						
						updateDutyA2(sum/6); // Actualizar el valor de los lados
						
						updateDutyB2(sum/6);*/
						break;
					
					case 1:
						break;
						
					case 2:
						updateDutyA1((B/15) + 13); // Actualizar el valor de parpados izquierdos
						updateDutyB1((A/15) + 16);
						
						updateDutyA2((C/9)+ 12); // Actualizar el valor de los lados
						
						updateDutyB2((D/8)+ 16);
						
						_delay_ms(4);
						
						break;
						
					default:
						break;
				}
				
				
				
				break;
				
			default:
				break;	
		}
    }
}

//********************************************************************************************************************************************
// Funciones
//********************************************************************************************************************************************

void setup(void)
{
	CLKPR |= (1 << CLKPCE);
	CLKPR |= (1 << CLKPS0); //8MHz
	
	DIDR0 |= (1 << ADC5D) | (1 << ADC4D); //Apagar la entrada digital de PC5 y PC4
	
	DDRC &= ~((1 << DDC0) | (1 << DDC1) | (1 << DDC2) |(1 << DDC3)); // Setear los botones de posicion
	PORTC |= (1 << PORTC0) | (1 << PORTC1) | (1 << PORTC2) | (1 << PORTC3);
	
	DDRB &= ~(1 << DDB4); // Setear el boton de modo
	PORTB |= (1 << PORTB4);
	
	DDRD |= (1 << DDD4) | (1 << DDD2) | (1 << DDD7); // SALIDAS DE LA LED
	// Iniciamos con modo 0
	PORTD &= ~(1 << PORTD4);
	PORTD |= (1 << PORTD7);
	
	//TCCR0A = 0; // Limpiar registros del PWM
	//TCCR0B = 0;
	
	TCCR1A = 0; // Limpiar registros del PWM
	TCCR1B = 0;
	
	TCCR2A = 0; // Limpiar registros del PWM
	TCCR2B = 0;
	
	initUART();
	
	setpinchange();
	
	//setPWM0fastA(0, _FF0, 1024); // setear el PWM0 Fast
	
	//setPWM0fastB(0, _FF0, 1024);
	
	setPWM1fastA(0, _8bits, 1024); // setear el PWM1 Fast
	
	setPWM1fastB(0, _8bits, 1024);
	
	setPWM2fastA(0, _FF2, 1024); // setear el PWM2 Fast
	
	setPWM2fastB(0, _FF2, 1024);
	
	setADC(externo, izquierda, 7); // Setear el ADC
	
	controlADC(1, 0, 1, 128); // Setear los registros de control del ADC
	
	sei(); // Activar interrupciones globales
}

void setpinchange(void){
	PCICR |= (1 << PCIE1) | (1 << PCIE0); // Setear los registros de control para pcint 0 y 1
	
	PCMSK0 |= (1 << PCINT4); // Setear la mascara para PB5
	PCMSK1 |= (1 << PCINT8) | (1 << PCINT9) | (1 << PCINT10) | (1 << PCINT11); // Setear la mascara de los botones en PINC
}

void initUART(){
	DDRD |= (1 << DDD1);
	DDRD &= ~(1 << DDD0);
	
	UCSR0A = 0;
	UCSR0A |= (1 << U2X0);
	
	UCSR0B = 0;
	UCSR0B |= (1 << RXCIE0) | (1 << RXEN0) | (1 << TXEN0);
	
	UCSR0C = 0;
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
	
	UBRR0 = 52;
}

//********************************************************************************************************************************************
// Interrupciones
//********************************************************************************************************************************************

ISR(PCINT0_vect){
	uint8_t bttn_modo = PINB & (1 << PINB4);
	
	if (bttn_modo == 0){
		if (modo < 3){
			modo++;
		}
		else {
			modo = 0;
		}
		
		switch(modo){
			case 0:
				PORTD &= ~(1 << PORTD4);
				PORTD |= (1 << PORTD7);
				break;
			case 1:
				PORTD &= ~(1 << PORTD7);
				PORTD |= (1 << PORTD2);
				break;
			case 2:
				PORTD &= ~(1 << PORTD2);
				PORTD |= (1 << PORTD4);
				break;
			case 3:
				PORTD |= (1 << PORTD4) | (1 << PORTD7);
				break;
			default:
				break;
		}
	}
	
	PCIFR |= (1 << PCIF0);
}

ISR(ADC_vect){
	POT = (ADMUX & 0x0F); //Leer que potenciometro activo la interrupcion
	
	if (POT == 7){
		POT1 = ADCH; //Leer el potenciometro activado
		setADC(externo, izquierda, 6); //Setear el siguiente potenciometro
	}
	else if (POT == 6){
		POT2= ADCH;
		setADC(externo, izquierda, 5);
	}
	else if (POT == 5) {
		POT3 = ADCH;
		setADC(externo, izquierda, 4);
	}
	else {
		POT4 = ADCH;
		setADC(externo, izquierda, 7);
	}
	ADCSRA |= (1 << ADIF); //Apagar la bandera de ADC
}

ISR(PCINT1_vect){
	uint8_t bttn_ser1 = PINC & (1 << PINC0);
	uint8_t bttn_ser2 = PINC & (1 << PINC1);
	uint8_t bttn_ser3 = PINC & (1 << PINC2);
	uint8_t bttn_ser4 = PINC & (1 << PINC3);

	cli();
	
	switch (modo){
		case 0:
			break;
		
		case 1:
			if (bttn_ser1 == 0){
				address = 0;
				eeprom_write_byte(address, POT1);
				address++;
				eeprom_write_byte(address, POT2);
				address++;
				eeprom_write_byte(address, POT3);
				address++;
				eeprom_write_byte(address, POT4);
			}
			else if(bttn_ser2 == 0){
				for (i = 0; i < 4; i++){
					address++;
				}
				eeprom_write_byte(address, POT1);
				address++;
				eeprom_write_byte(address, POT2);
				address++;
				eeprom_write_byte(address, POT3);
				address++;
				eeprom_write_byte(address, POT4);
			}
			else if (bttn_ser3 == 0){
				for (i = 0; i < 8; i++){
					address++;
				}
				eeprom_write_byte(address, POT1);
				address++;
				eeprom_write_byte(address, POT2);
				address++;
				eeprom_write_byte(address, POT3);
				address++;
				eeprom_write_byte(address, POT4);
			}
			else if (bttn_ser4 == 0){
				for (i = 0; i < 12; i++){
					address++;
				}
				eeprom_write_byte(address, POT1);
				address++;
				eeprom_write_byte(address, POT2);
				address++;
				eeprom_write_byte(address, POT3);
				address++;
				eeprom_write_byte(address, POT4);
			}
			address = 0;
			break;
			
		case 2:
			if (bttn_ser1 == 0){
				address = 0;
				A = eeprom_read_byte(address);
				address++;
				B = eeprom_read_byte(address);
				address++;
				C = eeprom_read_byte(address);
				address++;
				D = eeprom_read_byte(address);
			}
			else if (bttn_ser2 == 0){
				for (i = 0; i < 4; i++){
					address++;
				}
				A = eeprom_read_byte(address);
				address++;
				B = eeprom_read_byte(address);
				address++;
				C = eeprom_read_byte(address);
				address++;
				D = eeprom_read_byte(address);
			}
			else if (bttn_ser3 == 0){
				for (i = 0; i < 8; i++){
					address++;
				}
				A = eeprom_read_byte(address);
				address++;
				B = eeprom_read_byte(address);
				address++;
				C = eeprom_read_byte(address);
				address++;
				D = eeprom_read_byte(address);
			}
			else if (bttn_ser4 == 0){
				for (i = 0; i < 12; i++){
					address++;
				}
				A = eeprom_read_byte(address);
				address++;
				B = eeprom_read_byte(address);
				address++;
				C = eeprom_read_byte(address);
				address++;
				D = eeprom_read_byte(address);
			}
			address = 0;
			break;
			
		case 3:
			break;
			
		default:
			break;
	}
	sei();
	PCIFR |= (1 << PCIF1);
}

ISR(USART_RX_vect){
	
	while (!(UCSR0B & (1 << RXC0)));
	recibido = UDR0;
	if (recibido == 77){
		modoUART = 0;
		PORTD &= ~((1 << PORTD4) | (1 << PORTD2));
		PORTD |= (1 << PORTD7);
		
	}
	else if (recibido == 69){
		modoUART = 1;
		PORTD &= ~((1 << PORTD7) | (1 << PORTD4));
		PORTD |= (1 << PORTD2);
	}
	else if (recibido == 76){
		modoUART = 2;
		PORTD &= ~((1 << PORTD2)| (1 << PORTD7));
		PORTD |= (1 << PORTD4);
	}
	
	switch (modoUART){
		case 0:
			/*if (recibido == 65){
				while (!(UCSR0B & (1 << RXC0)));
				recibido = UDR0;
				sum = 0;
				cont = 0;
				while (recibido != 10){
					cont++;
					
					if (cont == 1){
						num1 = recibido - 48;
					}
					else if (cont == 2){
						num2 = recibido - 48;
					}
					else if (cont == 2){
						num3 = recibido - 48;
					}
					
					while (!(UCSR0B & (1 << RXC0)));
					recibido = UDR0;
				}
				
				if (cont == 1){
					sum = num1;
				}
				else if (cont == 2){
					sum = (num1*10) + num2;
				}
				else if (cont == 3){
					sum = (num1*100) + (num2*10) + num1;
				}
			}
			else if (recibido == 66){
				
			}
			if (recibido == 67){
				
			}
			else if (recibido == 68){
				
			}*/
			break;
		
		case 1:
			break;
			
		case 2:
			if (recibido == 97){
				address = 0;
				A = eeprom_read_byte(address);
				address++;
				B = eeprom_read_byte(address);
				address++;
				C = eeprom_read_byte(address);
				address++;
				D = eeprom_read_byte(address);
			}
			else if (recibido == 98){
				for (i = 0; i < 4; i++){
					address++;
				}
				A = eeprom_read_byte(address);
				address++;
				B = eeprom_read_byte(address);
				address++;
				C = eeprom_read_byte(address);
				address++;
				D = eeprom_read_byte(address);
			}
			else if (recibido == 99){
				for (i = 0; i < 8; i++){
					address++;
				}
				A = eeprom_read_byte(address);
				address++;
				B = eeprom_read_byte(address);
				address++;
				C = eeprom_read_byte(address);
				address++;
				D = eeprom_read_byte(address);
			}
			else if (recibido == 100){
				for (i = 0; i < 12; i++){
					address++;
				}
				A = eeprom_read_byte(address);
				address++;
				B = eeprom_read_byte(address);
				address++;
				C = eeprom_read_byte(address);
				address++;
				D = eeprom_read_byte(address);
			}
			address = 0;
			break;
			
		default:
			break;
	}

}
