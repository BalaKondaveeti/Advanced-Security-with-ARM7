#include "LPC214x.h"
#include "SIM900.h"
#include "SmokeSensor.h"

// Define sensor pins
#define SMOKE_SENSOR_PIN 1

// Initialize sensor objects
SmokeSensor smokeSensor(SMOKE_SENSOR_PIN);

// Initialize GSM module
SIM900 gsm;

// Alert recipient phone number
const char* alertPhoneNumber = "+9194949061928";

void setup() {
    gsm.init();
}

void loop() {
    gsm.sendSMS(alertPhoneNumber, "This thing is sending messages");

    if (smokeSensor.readGasConcentration() > 50.0) {
        gsm.sendSMS(alertPhoneNumber, "Alert: High gas concentration detected!");
    }
}

int main() {
    setup();
    while (1) {
        loop();
    }
    return 0; // Should never reach this point
}
