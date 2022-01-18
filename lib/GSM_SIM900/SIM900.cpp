#include "SIM900.h"

// Constructor implementation
SIM900::SIM900() {
    init(); // Initialize the SIM900 module upon object creation
}

// Initialize SIM900 module
void SIM900::init() {
    setupUART(); // Set up UART for SIM900 communication
    sendCommand("AT"); // Check if the module is ready
    sendCommand("ATE0"); // Turn off echo for cleaner communication
}

// Send SMS through the SIM900 module
void SIM900::sendSMS(const char* number, const char* message) {
    char cmd[30];

    // Set SMS text mode
    sendCommand("AT+CMGF=1\r");
    
    // Set the recipient's phone number
    sprintf(cmd, "AT+CMGS=\"%s\"\r", number);
    sendCommand(cmd);
    
    // Send the SMS content
    sendCommand(message);
    sendCommand("\x1A"); // End SMS with a Ctrl-Z/EOF character
}

// Send AT command to the SIM900 module
void SIM900::sendCommand(const char* cmd) {
    // Assuming UART_Write is a function to write data over UART
    UART_Write(LPC_UART1, (uint8_t*)cmd, strlen(cmd));
}

// Setup UART for SIM900 communication
void SIM900::setupUART() {
    // Assuming UART_Init is a pre-defined function to initialize UART
    UART_Init(LPC_UART1, 9600); // Initialize UART1 for SIM900, baud rate 9600
}
