#include "LPC214x.h"
#include "SIM900.h"
#include "SoundSensor.h"
#include "SmokeSensor.h"
#include "TouchSensor.h"
#include "Ultrasonic.h"

// Define sensor pins
#define SOUND_SENSOR_PIN 0
#define SMOKE_SENSOR_PIN 1
#define TOUCH_SENSOR_PIN 2
#define ULTRASONIC_TRIG_PIN 3
#define ULTRASONIC_ECHO_PIN 4

// Initialize sensor objects
SoundSensor soundSensor(SOUND_SENSOR_PIN);
SmokeSensor smokeSensor(SMOKE_SENSOR_PIN);
TouchSensor touchSensor(TOUCH_SENSOR_PIN);
Ultrasonic ultrasonicSensor(ULTRASONIC_TRIG_PIN, ULTRASONIC_ECHO_PIN);

// Initialize GSM module
SIM900 gsm;

// Alert recipient phone number
const char* alertPhoneNumber = "+9194949061928";

void setup() {
    // System initialization
    gsm.init();
}

void loop() {
    // Main loop to check sensor inputs and send alerts
    if (smokeSensor.readGasConcentration() > 50.0) { // Threshold for gas concentration
        gsm.sendSMS(alertPhoneNumber, "Alert: High gas concentration detected!");
    }

    if (soundSensor.readSoundLevel() > 75.0) { // Threshold for sound level
        gsm.sendSMS(alertPhoneNumber, "Alert: Loud noise detected!");
    }

    if (touchSensor.isTouched()) {
        gsm.sendSMS(alertPhoneNumber, "Alert: Unauthorized touch detected!");
    }

    float distance = ultrasonicSensor.measureDistance();
    if (distance < 10.0) { // Threshold for distance, e.g., object too close
        gsm.sendSMS(alertPhoneNumber, "Alert: Object detected nearby!");
    }

    // delay(1000);
}

int main() {
    setup();
    while (1) {
        loop();
    }
    return 0; // Should never reach this point
}
