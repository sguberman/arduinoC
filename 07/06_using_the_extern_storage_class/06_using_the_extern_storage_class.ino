extern int number;

void setup() {
    Serial.begin(9600);
}

void loop() {
    number *= number;
    Serial.println(number);
}
