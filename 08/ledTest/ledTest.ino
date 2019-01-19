#define DEBUG

#define LED1 11
#define LED2 10


void setup()
{
    Serial.begin(9600);
    
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
}

void loop()
{
    int goodInput = -1;
    int ledCombo = -1;
    
    goodInput = getInput(&ledCombo);
    
    #ifdef DEBUG
    Serial.print("goodInput = ");
    Serial.print(goodInput);
    Serial.print(" ledCombo = ");
    Serial.println(ledCombo);
    #endif
    
    if (goodInput)
    {
        setLEDs(ledCombo);
    }
}

int getInput(int *ledCombo)
{
    char c;
    while (true)
    {
        if (Serial.available())
        {
            c = Serial.read();
            if (isdigit(c))
            {
                int temp = atoi(c);
                if (temp >= 0 && temp < 4)
                {
                    *ledCombo = temp;
                    return 1;
                }
            } else {
                return 0;
            }
        }
    }
}

void setLEDs(int ledCombo)
{
    switch (ledCombo)
    {
        case 0:
            digitalWrite(LED1, LOW);
            digitalWrite(LED2, LOW);
            break;
        case 1:
            digitalWrite(LED1, HIGH);
            digitalWrite(LED2, LOW);
            break;
        case 2:
            digitalWrite(LED1, LOW);
            digitalWrite(LED2, HIGH);
            break;
        case 3:
            digitalWrite(LED1, HIGH);
            digitalWrite(LED2, HIGH);
            break;
    }
}