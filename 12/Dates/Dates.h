/*
  Dates.h - Library for finding if a year is a leap year
            and the date for Easter for a given year.
  Created and modified by Dr. Jack Purdum, Dec 25, 2014
  Released into the public domain.
*/
#ifndef Dates_h  // prevent double including
    #define Dates_h
    
    #include "Arduino.h"
    
    class Dates
    {
        public:
            #define ASCIIZERO 48
            
            struct easter {
                int month;
                int day;
                int year;
                int leap;
                char easterStr[11];
            };
            struct easter myEaster;
            
            // function prototypes
            int isLeapYear(int year);
            void getEaster(Dates *myEaster);
    };
#endif