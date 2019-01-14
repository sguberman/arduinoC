/**
  Program: determine if the user typed a leap year at the serial prompt.
    Assume only valid years are typed.
  
  Author: Dr. Purdum, Nov 17, 2014
          Seth Guberman, Jan 14, 2019
**/


#define MAXCHARS 10

void setup() {
    Serial.begin(9600);
}


void loop() {
    if (Serial.available() > 20) {
        int bufferCount;
        int year;
        char myData[MAXCHARS + 1];
        
        bufferCount = readLine(myData);
        year = atoi(myData);
        Serial.print("Year: ");
        Serial.print(year);
        Serial.print(" is ");
        if (isLeapYear(year) == 0) {
            Serial.print("not ");
        }
        Serial.println("a leap year.")
    }
}


/*****
  Purpose: Determine if a given year is a leap year

  Parameters:
    int year        The year to test

  Return value:
    int             1 if leap year, 0 otherwise
*****/
int isLeapYear(int year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        return 1;  // leap year
    } else {
        return 0;  // not a leap year
    }
}


/*****
  Purpose: Read data from serial port until newline ('\n')
  
  Parameters:
    char str[]  character array treated as null-terminated string
  
  Return value:
    int         the number of characters read for the string
  
  CAUTION: This method will sit here forever if no input is nread from the serial port and no newline character is entered.
 *****/
 int readLine(char str[]) {
    char c;
    int index = 0;
    
    while (true) {
        if (Serial.available() > 0) {
            index = Serial.readBytesUntil('\n', str, MAXCHARS);
            str[index] = '\0';
            break;
        }
    }
    
    return index;
}