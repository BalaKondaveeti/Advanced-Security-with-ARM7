#ifndef SOUNDSSENSOR_H
#define SOUNDSSENSOR_H

class SoundSensor {
public:
    SoundSensor(int pin); // Constructor with analog pin
    float readSoundLevel(); // Read sound level from the sensor

private:
    int sensorPin; // Analog pin connected to the sound sensor
};

#endif // SOUNDSSENSOR_H
