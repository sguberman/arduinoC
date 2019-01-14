// 1. Initialization
#define MAX 5000L
#define MIN 0L
#define TARGETVALUE 2500L

#define MAXRECYCLES 5
#define FOUNDITPIN 10
#define RECYCLEPIN 11
#define PAUSE 1000

int foundIt = FOUNDITPIN;
int recycle = RECYCLEPIN;
long randomNumber;
int recycleCounter = 0;
int counter = 0;

void setup() {
    Serial.begin(9600);
    pinMode(foundIt, OUTPUT);
    pinMode(recycle, OUTPUT);
    randomSeed(analogRead(A0));
}


void loop() {
    while (true) {
        // 2. Input
        randomNumber = generateRandomNumber();
        
        // 3. Process
        if (randomNumber == TARGETVALUE) {
            // 4. Output
            Serial.print("counter = ");
            Serial.print(counter, DEC);
            Serial.print(" recycleCounter = ");
            Serial.println(recycleCounter, DEC);
            ToggleLED(foundIt, PAUSE);
        }

        // 3. Process
        counter++;
        if (counter < 0) {  // we've overflowed an int
            counter = 0;
            recycleCounter++;
            // 4. Output
            Serial.print("recycleCounter = ");
            Serial.println(recycleCounter, DEC);
            ToggleLED(recycle, PAUSE);
        }

        // 3. Process
        if (recycleCounter == MAXRECYCLES) {
            // 5. Terminate
            FakeAnEnd();
        }
    }
}

long generateRandomNumber() {
    return random(MIN, MAX);
}

void FakeAnEnd() {
    while (true) {
        ;
    }
}

void ToggleLED(int whichLED, int howLong) {
    digitalWrite(whichLED, HIGH);
    delay(howLong);
    digitalWrite(whichLED, LOW);
}
