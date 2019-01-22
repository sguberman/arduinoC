struct servicePeople
{
    int ID;
    char Name[20];
    char PW[10];
    long Phone;
} myServicePeople, yourServicePeople;

void setup()
{
    Serial.begin(9600);
    Serial.print("myServicePeople lvalue: ");
    Serial.print((int) &myServicePeople);
    Serial.print(" yourServicePeople lvalue: ");
    Serial.println((int) &yourServicePeople);

    yourServicePeople.ID = 205;  // rvalue assignment

    Serial.print("myServicePeople.ID rvalue: ");
    Serial.print(myServicePeople.ID);
    Serial.print(" yourServicePeople.ID rvalue: ");
    Serial.println(yourServicePeople.ID);

    myServicePeople = yourServicePeople;  // copy entire struct

    Serial.println("\nAfter assignment:\n");
    Serial.print("myServicePeople.ID rvalue: ");
    Serial.print(myServicePeople.ID);
    Serial.print(" yourServicePeople.ID rvalue: ");
    Serial.println(yourServicePeople.ID);
    Serial.print("myServicePeople.ID lvalue: ");
    Serial.print((int) &myServicePeople.ID);
    Serial.print(" yourServicePeople.ID lvalue: ");
    Serial.println((int) &yourServicePeople.ID);
    Serial.print("A servicePeople struct takes ");
    Serial.print(sizeof(servicePeople));
    Serial.println(" bytes of storage.");
}

void loop() {}
