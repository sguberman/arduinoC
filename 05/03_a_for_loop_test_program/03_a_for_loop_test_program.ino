#define LED 13


void setup() {
    pinMode(LED, OUTPUT);
}


void loop() {
    int counter;
    for (counter = 0; counter < 1000; counter++) {
        if (counter % 2 == 0) {
            digitalWrite(LED, HIGH);
        } else {
            digitalWrite(LED, LOW);
        }
        delay(500);
    }
}
