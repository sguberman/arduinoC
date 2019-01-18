void setup()
{
    Serial.begin(9600);
    int number = 10;
    
    Serial.print("lvalue for number is ");
    Serial.print((int) &number);
    Serial.print(" rvalue for number is ");
    Serial.println(number);
    squareIt(number);
    Serial.print("After call: rvalue for number is ");
    Serial.println(number);
}

void loop() {}

void squareIt(int temp)
{
    Serial.print("In squareIt(), lvalue for temp is ");
    Serial.print((int) &temp);
    Serial.print(" rvalue for temp is ");
    Serial.println(temp);
    temp *= temp;
    Serial.print("The new rvalue for temp is ");
    Serial.println(temp);
}