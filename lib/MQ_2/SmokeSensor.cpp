#include "SmokeSensor.h"
#include "LPC214x.h" // Include LPC2148 specifics

SmokeSensor::SmokeSensor(int pin) : sensorPin(pin) {}

float SmokeSensor::readGasConcentration() {
    // For demonstration purposes, we'll just simulate a gas concentration reading.
    // In a real scenario, you'd use an ADC to read the analog value from the sensor.
    // Let's assume we're using a 10-bit ADC with LPC2148, where the value can range from 0 to 1023.
    // The returned value would be a representation of the gas concentration.
    int analogValue = ADC_read(sensorPin);
    float concentration = (analogValue / 1023.0) * 100; // Convert to percentage for simplicity
    return concentration; // Returns gas concentration as a percentage
}

// Assume a function for reading from ADC (not part of standard LPC214x.h)
int ADC_read(int pin) {
    return 512; // Returning dummy value
}
