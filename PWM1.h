/*
 * PWM1.h
 *
 * Created: 5/5/2024 10:08:11 PM
 *  Author: Fatima
 */ 

#ifndef PWM1_H_
#define PWM1_H_

#include <avr/io.h>
#include <stdint.h>

#define _8bits 0
#define _9bits 1
#define _10bits 2
#define _ICR1 3
#define _OCR1 4


void setPWM1fastA(uint8_t invertido, uint8_t modo, uint16_t prescaler);

void updateDutyA1(uint8_t dutycycle);

void setPWM1fastB(uint8_t invertido, uint8_t modo, uint16_t prescaler);

void updateDutyB1(uint8_t dutycycle);


#endif /* PWM1_H_ */
