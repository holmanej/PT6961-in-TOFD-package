
#include "Main.h"

void main() {
    
    MCU_Initialize();
    
    I2C_Transmit(WR_CMD, 0x81, 255);
    I2C_Transmit(WR_CMD, 0xAF, 0);
    I2C_Transmit(WR_CMD, 0xA6, 0);
    
    while(1) {
        
    }
    
}

void MCU_Initialize() {

    // Configure oscillator for 32 MHz
    OSCCON = 0b01110000;
    // Configure I2C outputs
    RB6PPS = 0b10000;
    RB4PPS = 0b10001;
    // Configure I2C module
    SSP1STAT = 0b10000000;
    SSP1CON1 = 0b00101000;
    SSP1CON2 = 0b00010000;
    SSP1CON3 = 0b00000000;
    SSP1ADD = 0b000000111;
}

uint8_t I2C_Transmit(uint8_t addr, uint8_t cmd, uint8_t data) {
    while(!SSP1IF);
    SSP1IF = 0;
    SEN = 1;
    while(!SSP1IF);
    SSP1IF = 0;
    SSP1BUF = addr;
    while(!SSP1IF);
    SSP1IF = 0;
    SSP1BUF = cmd;
    while(!SSP1IF);
    SSP1IF = 0;
    SSP1BUF = data;
    while(!SSP1IF);
    SSP1IF = 0;
    PEN = 1;
    return(0);
}