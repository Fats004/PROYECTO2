/*
 * PWM2.h
 *
 * Created: 5/5/2024 10:09:47 PM
 *  Author: Fatima
 */ 



#ifndef PWM2_H_
#define PWM2_H_


#include <avr/io.h>
#include <stdint.h>

#define _FF2 0
#define _OCR2 1

void setPWM2fastA(uint8_t invertido, uint8_t modo, uint16_t prescaler);

void updateDutyA2(uint8_t dutycycle);

void setPWM2fastB(uint8_t invertido, uint8_t modo, uint16_t prescaler);

void updateDutyB2(uint8_t dutycycle);

#endif /* PWM2_H_ */
