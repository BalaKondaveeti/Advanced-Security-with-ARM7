#ifndef TOUCHSENSOR_H
#define TOUCHSENSOR_H

class TouchSensor {
public:
    TouchSensor(int pin); // Constructor with digital pin
    bool isTouched(); // Returns true if the sensor is touched

private:
    int sensorPin; // Digital pin connected to the TTP223 touch sensor
};

#endif // TOUCHSENSOR_H
