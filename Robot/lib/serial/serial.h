/*
 * Serial.h
 *
 * Created: 2/03/2015 5:41:43 PM
 *  Author: Robert
 */

#ifndef SERIAL_H_
#define SERIAL_H_

#ifdef __cplusplus
extern "C" {
#endif

// include libraries
#include <avr/io.h>

#define USART_BAUDRATE 9600

// macros
#define BAUD_PRESCALE \
  ((((F_CPU / 16) + (USART_BAUDRATE / 2)) / (USART_BAUDRATE)) - 1)

// function prototypes
void serial0_init(void);
void serial0_print_string(char* string_pointer);
void serial0_write_byte(uint8_t data_byte);

void serial1_init(void);
void serial1_print_string(char* string_pointer);
void serial1_write_byte(uint8_t data_byte);

void serial2_init(void);
void serial2_print_string(char* string_pointer);
void serial2_write_byte(uint8_t data_byte);

void serial3_init(void);
void serial3_print_string(char* string_pointer);
void serial3_write_byte(uint8_t data_byte);

void serial0_init(void) {
  UCSR0B = (1 << RXEN0) |
           (1 << TXEN0);  // turn on the transmission and reception circuitry
  UCSR0C = (1 << UCSZ00) | (1 << UCSZ01);  // use 8- bit character sizes
  UBRR0 = BAUD_PRESCALE;  // load baud rate prescaler into register
}  // end serial2_init

void serial1_init(void) {
  UCSR1B = (1 << RXEN1) |
           (1 << TXEN1);  // turn on the transmission and reception circuitry
  UCSR1C = (1 << UCSZ10) | (1 << UCSZ11);  // use 8- bit character sizes
  UBRR1 = BAUD_PRESCALE;  // load baud rate prescaler into register
}  // end serial2_init

void serial2_init(void) {
  UCSR2B = (1 << RXEN2) |
           (1 << TXEN2);  // turn on the transmission and reception circuitry
  UCSR2C = (1 << UCSZ20) | (1 << UCSZ21);  // use 8- bit character sizes
  UBRR2 = BAUD_PRESCALE;  // load baud rate prescaler into register
}  // end serial2_init

void serial3_init(void) {
  UCSR3B = (1 << RXEN3) |
           (1 << TXEN3);  // turn on the transmission and reception circuitry
  UCSR3C = (1 << UCSZ30) | (1 << UCSZ31);  // use 8- bit character sizes
  UBRR3 = BAUD_PRESCALE;  // load baud rate prescaler into register
}  // end serial3_init

void serial0_print_string(
    char* string_pointer)  // function to print a string via serial
{
  while (*string_pointer)  // while not null character (end of string)
  {
    while ((UCSR0A & (1 << UDRE0)) == 0) {
    }                        // wait until data register is ready
    UDR0 = *string_pointer;  // send what's at the string pointer to serial data
                             // register
    string_pointer++;        // increment string pointer to go to next letter in
                             // string
  }
}  // end serial0_print_string

void serial0_write_byte(uint8_t data_byte) {
  while ((UCSR0A & (1 << UDRE0)) == 0) {
  }  // wait until data register is ready
  UDR0 = data_byte;
}

void serial1_print_string(
    char* string_pointer)  // function to print a string via serial
{
  while (*string_pointer)  // while not null character (end of string)
  {
    while ((UCSR1A & (1 << UDRE1)) == 0) {
    }                        // wait until data register is ready
    UDR1 = *string_pointer;  // send what's at the string pointer to serial data
                             // register
    string_pointer++;        // increment string pointer to go to next letter in
                             // string
  }
}  // end serial1_print_string

void serial1_write_byte(uint8_t data_byte) {
  while ((UCSR1A & (1 << UDRE1)) == 0) {
  }  // wait until data register is ready
  UDR1 = data_byte;
}

void serial2_print_string(
    char* string_pointer)  // function to print a string via serial
{
  while (*string_pointer)  // while not null character (end of string)
  {
    while ((UCSR2A & (1 << UDRE2)) == 0) {
    }                        // wait until data register is ready
    UDR2 = *string_pointer;  // send what's at the string pointer to serial data
                             // register
    string_pointer++;        // increment string pointer to go to next letter in
                             // string
  }
}  // end serial2_print_string

void serial2_write_byte(uint8_t data_byte) {
  while ((UCSR2A & (1 << UDRE2)) == 0) {
  }  // wait until data register is ready
  UDR2 = data_byte;
}

void serial3_print_string(
    char* string_pointer)  // function to print a string via serial
{
  while (*string_pointer)  // while not null character (end of string)
  {
    while ((UCSR3A & (1 << UDRE3)) == 0) {
    }                        // wait until data register is ready
    UDR3 = *string_pointer;  // send what's at the string pointer to serial data
                             // register
    string_pointer++;        // increment string pointer to go to next letter in
                             // string
  }
}  // end serial3_print_string

void serial3_write_byte(uint8_t data_byte) {
  while ((UCSR3A & (1 << UDRE3)) == 0) {
  }  // wait until data register is ready
  UDR3 = data_byte;
}

#ifdef __cplusplus
}
#endif

#endif /* SERIAL_H_ */