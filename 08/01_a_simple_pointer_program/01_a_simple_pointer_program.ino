#include <stdio.h>


int counter = 0;


void setup() {
    int number = 5;
    int *ptrNumber = NULL;
    int k;

    Serial.begin(115200);
    Serial.print("The lvalue for ptrNumber is ");
    Serial.print((long) &ptrNumber, DEC);
    Serial.print(" and the rvalue is ");
    Serial.println((long) ptrNumber, DEC);

    ptrNumber = &number;
    *ptrNumber = 10;
    k = *ptrNumber;

    Serial.print("The lvalue for number is ");
    Serial.print((long) &number, DEC);
    Serial.print(" and the rvalue is ");
    Serial.println((int) number, DEC);

    Serial.print("The lvalue for k is ");
    Serial.print((long) &k, DEC);
    Serial.print(" and the rvalue is ");
    Serial.println(k, DEC);
}

void loop() {
}
