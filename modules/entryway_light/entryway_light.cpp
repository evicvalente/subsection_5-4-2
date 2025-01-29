#include "mbed.h"
#include "entryway_light.h"
#include "light_sensor.h"

#define NIGHT_THRESHOLD 0.6  // Adjust based on environment
#define DAY_THRESHOLD 0.2

DigitalOut entrywayLight(LED2); // GPIO pin for light control

void entrywayLightInit() {
    entrywayLight = 0; // Initialize light to OFF
}

void entrywayLightUpdate() {
    float lightLevel = lightSensorRead();

    if (lightLevel < NIGHT_THRESHOLD) {
        entrywayLight = 1; // Turn ON light
    } else if (lightLevel > DAY_THRESHOLD) {
        entrywayLight = 0; // Turn OFF light
    }
}