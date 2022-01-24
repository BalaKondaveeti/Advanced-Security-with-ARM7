#include "Ultrasonic.h"
#include "LPC214x.h" // Include LPC2148 specifics
#include <sys/time.h> // For time measurement

Ultrasonic::Ultrasonic(int triggerPin, int echoPin) : trigPin(triggerPin), echoPin(echoPin) {}

float Ultrasonic::measureDistance() {
    triggerPulse(); 

    // For this example, we'll simulate the time it takes for the pulse to return
    float simulatedEchoTime = 0.01; // Simulated time in seconds for the echo to return

    // Speed of sound in air at sea level is approximately 343 m/s. 
    // Distance = (Time x Speed of Sound) / 2
    float distance = (simulatedEchoTime * 34300) / 2; // Distance in centimeters

    return distance; // Returns the measured distance in centimeters
}

void Ultrasonic::triggerPulse() {
    // Need to implement
}
