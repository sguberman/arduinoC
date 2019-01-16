#define LED 13


void setup()
{
    pinMode(LED, OUTPUT);
}

void loop()
{
    static int state = HIGH;
    blinkLED(LED, &state);
}

/*****
  Purpose: Blink the onboard LED using a pointer
  
  Parameters:
    int pin             the pin attached to the LED
    int *whichState     pointer to the state variable
  
  Returns:
    void
*****/
void blinkLED(pin, *whichState)
{
    digitalWrite(pin, *whichState);
    delay(1000);
    *whichState = !(*whichState)
}