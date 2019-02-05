#include <Dates.h>
Dates myDates;

void setup() {
    int i;
    Serial.begin(9600);

    for (i = 2000; i < 2016; i++)
    {
        Serial.print(i);
        Serial.print(" is ");
        if (myDates.isLeapYear(i) == 0)
        {
            Serial.print("not ");
        }
        Serial.print("a leap year and Easter is on ");
        myDates.myEaster.year = i;
        myDates.getEaster(&myDates);
        Serial.print(myDates.myEaster.easterStr);
        Serial.print("  ");
        Serial.print(myDates.myEaster.month);
        Serial.print("  ");
        Serial.print(myDates.myEaster.day);
        Serial.print("  ");
        Serial.println(myDates.myEaster.year);
    }
}

void loop() {}
