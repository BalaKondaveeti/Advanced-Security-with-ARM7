#ifndef SIM900_H
#define SIM900_H

#include "LPC214x.h"

class SIM900 {
public:
    SIM900(); // Constructor
    void init(); // Initialize SIM900 module
    void sendSMS(const char* number, const char* message); // Send SMS function

private:
    void sendCommand(const char* cmd); // Send AT commands to the SIM900 module
    void setupUART(); // UART setup specific for SIM900 communication
};

#endif // SIM900_H
