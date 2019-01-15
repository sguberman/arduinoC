void setup() {
    Serial.begin(9600);
}

void loop() {
    while (true) {
        Serial.println(myCounter());
    }
}

int myCounter() {
    static int counter = 0;  // value of counter is preserved between function calls
    return ++counter;
}
