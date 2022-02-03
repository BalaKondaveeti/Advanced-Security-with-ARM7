#include "Ultrasonic.h"

// Constructor
Ultrasonic::Ultrasonic(int triggerPin, int echoPin) : trigPin(triggerPin), echoPin(echoPin) {
    // Set trigger pin as output
    GPIO_SetDir(trigPin, GPIO_OUTPUT);
    // Set echo pin as input
    GPIO_SetDir(echoPin, GPIO_INPUT);
}

// Trigger the ultrasonic pulse
void Ultrasonic::triggerPulse() {
    GPIO_ClearPin(trigPin);         // Ensure trigger pin is low
    delayMicroseconds(2);           // Wait for 2 microseconds
    GPIO_SetPin(trigPin);           // Set trigger pin high
    delayMicroseconds(10);          // Wait for 10 microseconds
    GPIO_ClearPin(trigPin);         // Set trigger pin low again
}

// Measure distance
float Ultrasonic::measureDistance() {
    triggerPulse();

    // Wait for echo pin to go high
    while (!GPIO_ReadPin(echoPin));

    // Start timer
    Timer_Start();

    // Wait for echo pin to go low
    while (GPIO_ReadPin(echoPin));

    // Stop timer and get time
    uint32_t pulseWidth = Timer_Stop();

    // Calculate distance in centimeters (speed of sound is ~343 m/s)
    float distance = (pulseWidth / 2.0) * 0.0343;

    return distance;
}
