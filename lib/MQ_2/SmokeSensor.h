#ifndef SMOKESENSOR_H
#define SMOKESENSOR_H

class SmokeSensor {
public:
    SmokeSensor(int pin); // Constructor with analog pin
    float readGasConcentration(); // Method to read gas concentration

private:
    int sensorPin; // Analog pin connected to the MQ-2 sensor
};

#endif // SMOKESENSOR_H
