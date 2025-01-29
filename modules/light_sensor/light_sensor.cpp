#include "mbed.h"
#include "light_sensor.h"

AnalogIn ldrSensor(A2); // Define LDR sensor pin
#define NUM_SAMPLES 10

static float lightReadings[NUM_SAMPLES]={0};
static int index=0;

void lightSensorInit() {
    for (int i=0; i < NUM_SAMPLES; i++) {
        lightReadings[i]=0;
    }
}

float lightSensorRead(){
    // Take a new sample
    lightReadings[index] = ldrSensor.read(); // Read value (0.0 - 1.0)
    index=(index + 1) % NUM_SAMPLES;

    float sum = 0;
    for (int i = 0; i < NUM_SAMPLES; i++){
        sum += lightReadings[i];
    }
    return sum/NUM_SAMPLES;
}