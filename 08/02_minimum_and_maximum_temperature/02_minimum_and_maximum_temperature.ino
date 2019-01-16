#include <stdio.h>

#define READINGSPERDAY 24
#define VERYHIGHTEMPERATURE 200
#define VERYLOWTEMPERATURE -200

int todaysReadings[] = {62, 64, 65, 68, 70, 70, 71, 72, 74, 75, 76, 78,
                        79, 79, 78, 73, 70, 70, 69, 68, 64, 63, 61, 59};

void setup() {
    int lowTemp;
    int highTemp;
    int retVal;

    Serial.begin(115200);

    Serial.println("=== Before the function call:");
    Serial.print("The lvalue for lowTemp is ");
    Serial.print((long) &lowTemp, DEC);
    Serial.print(" and the rvalue is ");
    Serial.println((long) lowTemp, DEC);
    Serial.print("The lvalue for highTemp is ");
    Serial.print((long) &highTemp, DEC);
    Serial.print(" and the rvalue is ");
    Serial.println((long) highTemp, DEC);

    retVal = calculateMinMax(todaysReadings, &lowTemp, &highTemp);

    Serial.println("=== After the function call:");
    Serial.print("The lvalue for lowTemp is ");
    Serial.print((long) &lowTemp, DEC);
    Serial.print(" and the rvalue is ");
    Serial.println((long) lowTemp, DEC);
    Serial.print("The lvalue for highTemp is ");
    Serial.print((long) &highTemp, DEC);
    Serial.print(" and the rvalue is ");
    Serial.println((long) highTemp, DEC);
    Serial.println("\n");
}

void loop() {}

/*****
 * Purpose: Set the minimum and maximum temperatures based on
 *   the hourly readings for the day.
 * 
 * Parameter List:
 *   int temps[]        the array of temperatures
 *   int *minTemp       pointer to the minimum temperature value
 *   int *maxTemp       pointer to the maximum temperature value
 * 
 * Return value:
 *   int    the number of readings processed
 *****/
 int calculateMinMax(int temps[], int *minTemp, int *maxTemp) {
    *minTemp = VERYHIGHTEMPERATURE;
    *maxTemp = VERYLOWTEMPERATURE;

    int j;
    for (j = 0; j < READINGSPERDAY; j++) {
        if (temps[j] >= *maxTemp) {
            *maxTemp = temps[j];
        }
        if (temps[j] <= *minTemp) {
            *minTemp = temps[j];
        }
    }
    return j;
 }
