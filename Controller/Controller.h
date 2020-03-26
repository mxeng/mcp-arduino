// Example ATmega2560 Project
// File: ATmega2560Project.h
// Author: Robert Howie

#ifndef CONTROLLER_H_  // double inclusion guard
#define CONTROLLER_H_

// include standard libraries
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>

// include header files
#include "lib/adc/adc.h"                    //minimal adc lib
#include "lib/hd44780/hd44780.h"            //LCD lib
#include "lib/milliseconds/milliseconds.h"  //milliseconds timekeeping lib
#include "lib/serial/serial.h"              //minimal serial lib

// Disable Arduino functions
void digitalRead(int, int) {}
void digitalWrite(int, int) {}
void pinMode(int, int) {}

// constants
#define BUILD_DATE __TIME__ " " __DATE__ "\n"

#endif /* ATMEGA2560_H_ */