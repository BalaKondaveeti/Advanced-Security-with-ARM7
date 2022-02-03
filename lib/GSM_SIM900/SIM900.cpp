#include "SIM900.h"
#include <cstring>

// UART initialization for SIM900
void SIM900::setupUART() {
    // Assuming UART0 is used for SIM900
    // Configure pins for UART0 (P0.0 = TXD, P0.1 = RXD)
    PINSEL0 |= 0x00000005; // Select UART0 function for P0.0 and P0.1

    // Configure UART0
    // Assuming a system clock of 60 MHz and desired baud rate of 9600
    U0LCR = 0x83; // Enable DLAB
    U0DLL = 312;  // Set divisor for 9600 baud rate (DLL = 312, DLM = 0)
    U0DLM = 0;
    U0LCR = 0x03; // Disable DLAB, set 8 bit char, 1 stop bit, no parity

    // Enable UART0 RX interrupt
    U0IER = 0x01;
}

// Function to send AT commands to the SIM900 module
void SIM900::sendCommand(const char* cmd) {
    for (unsigned int i = 0; i < std::strlen(cmd); ++i) {
        while (!(U0LSR & 0x20)); // Wait for TX buffer to be empty
        U0THR = cmd[i];          // Transmit character
    }
    while (!(U0LSR & 0x20));     // Wait for last character to be sent
    U0THR = '\r';                // Send carriage return
}

// Constructor, initialization
SIM900::SIM900() {
    setupUART();
}

// Send SMS function
void SIM900::sendSMS(const char* number, const char* message) {
    sendCommand("AT+CMGF=1");  // Set SMS text mode
    sendCommand("AT+CMGS=\""); // Start SMS prompt
    sendCommand(number);       // Send phone number
    sendCommand("\"");         // End phone number
    sendCommand(message);      // Send message content
    sendCommand((char)26);     // Send CTRL+Z to send SMS
}
