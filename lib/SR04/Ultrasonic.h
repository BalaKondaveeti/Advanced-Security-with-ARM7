#ifndef ULTRASONIC_H
#define ULTRASONIC_H

class Ultrasonic {
public:
    Ultrasonic(int triggerPin, int echoPin); // Constructor with trigger and echo pins
    float measureDistance(); // Measure distance and return the value in centimeters

private:
    int trigPin; // Trigger pin for the SR04
    int echoPin; // Echo pin for the SR04
    void triggerPulse(); // Function to trigger the ultrasonic pulse
};

#endif // ULTRASONIC_H
