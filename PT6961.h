//------------------------------------------------------------------------------
// File:          PT6961.h
// Written By:    Eric Holman
// Date Created:  9/19/15
// Description:   4 digit MCU controller
// Compiler:	  XC32 v1.34
// Target:        PIC16
// Schematic(s):  Drawing L02-01
//
// Revision History (date, initials, description)
//   (none)
//------------------------------------------------------------------------------

#ifndef PT6961_H
#define	PT6961_H

#include <stdint.h>
#include <stdio.h>
#include <xc.h>

// Defines
#define TRIS_OUTPUT 0  // Used to set tristate to output
#define TRIS_INPUT 1   // Used to set tristate to input

#define cs_OUT PORTBbits.RB7
#define cs_TRIS TRISBbits.TRISB7

uint8_t numArray[16] = { (0b11111100), //0
                         (0b01100000), //1
                         (0b11011010), //2
                         (0b11110010), //3
                         (0b01100110), //4
                         (0b10110110), //5
                         (0b10111110), //6
                         (0b11100000), //7
                         (0b11111110), //8
                         (0b11110110), //9
                         (0b11101110), //A
                         (0b00111110), //b
                         (0b10011100), //C
                         (0b01111010), //d
                         (0b10011110), //E
                         (0b10001110)};//F

void PT6961_initialize();
void PT6961_SendByte(uint8_t byte);
void PT6961_ClearRAM();
void PT6961_SetDigit(uint8_t digit, uint8_t value);


#endif	/* PT6961_H */

