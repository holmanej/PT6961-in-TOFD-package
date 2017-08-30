//------------------------------------------------------------------------------
// File:          PT6961.c
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
#include "PT6961.h"
#include "PIC16_SPI.h"
#include "DCsupply.h"

void PT6961_initialize() {
    int8_t i;
    cs_TRIS = TRIS_OUTPUT;
    Delay(200);
    //display mode, 6dig, 12seg
    PT6961_SendByte(0b01000000);
    //set data
    PT6961_SendByte(0b00000010); 
    //Set RAM
    PT6961_ClearRAM();  
    //display on, full
    PT6961_SendByte(0b11110001);
    //send digit
    for (i = 0; i < 16; i++) {
        PT6961_SetDigit(0b01100011, numArray[i]);
        Delay(500);
    }
}

void PT6961_SendByte(uint8_t byte) {
    cs_OUT = 0;
    SPI_SendByte(byte);
    cs_OUT = 1;
}

void PT6961_ClearRAM() {
    uint8_t i;
    cs_OUT = 0;
    SPI_SendByte(0b00000011);
    for (i = 0; i < 8; i++) {
        SPI_SendByte(0x00); }
    cs_OUT = 1;
}

void PT6961_SetDigit(uint8_t digit, uint8_t value) {
    cs_OUT = 0;
    SPI_SendByte(digit);
    SPI_SendByte(value);
    cs_OUT = 1;
}