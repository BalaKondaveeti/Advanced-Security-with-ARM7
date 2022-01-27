#include "LPC214x.h"
#include "SIM900.h"
#include "SmokeSensor.h"

// Define sensor pins
#define SMOKE_SENSOR_PIN 1
#define ULTRASONIC_TRIG_PIN 3
#define ULTRASONIC_ECHO_PIN 4

// Initialize sensor objects
SmokeSensor smokeSensor(SMOKE_SENSOR_PIN);
Ultrasonic ultrasonicSensor(ULTRASONIC_TRIG_PIN, ULTRASONIC_ECHO_PIN);

// Initialize GSM module
SIM900 gsm;

// Alert recipient phone number
const char* alertPhoneNumber = "+9194949061928";

void setup() {
    gsm.init();
}

void loop() {
    if (smokeSensor.readGasConcentration() > 50.0) {
        gsm.sendSMS(alertPhoneNumber, "Alert: High gas concentration detected!");
    }

    float distance = ultrasonicSensor.measureDistance();
    if (distance < 10.0) { // Threshold for distance, e.g., object too close
        gsm.sendSMS(alertPhoneNumber, "Alert: Motion Detected!");
    }
    
    if (touchSensor.isTouched()) {
        gsm.sendSMS(alertPhoneNumber, "Alert: Unauthorized touch detected!");
    }

      if (soundSensor.readSoundLevel() > 75.0) { // Threshold for sound level
        gsm.sendSMS(alertPhoneNumber, "Alert: Loud noise detected!");
    }
}

int main() {
    setup();
    while (1) {
        loop();
    }
    return 0; // Should never reach this point
}
