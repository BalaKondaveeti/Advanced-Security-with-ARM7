#include "SoundSensor.h"
#include "LPC214x.h"

SoundSensor::SoundSensor(int pin) : sensorPin(pin) {
    PinMode(sensorPin, INPUT); // Set the sensor pin as input
    ADC_Init(); // Initialize ADC to read analog values
}

float SoundSensor::readSoundLevel() {
    int value = ADC_Read(sensorPin); // Read the analog value from the sound sensor
    float voltage = value * (3.3 / 1023.0); // Convert the value to voltage
    return voltage; // Return the voltage level as a proxy for sound level
}
