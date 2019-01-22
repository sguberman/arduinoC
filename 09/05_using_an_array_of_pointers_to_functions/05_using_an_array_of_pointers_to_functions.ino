/*
 * Purpose: illustrate how to use an array of pointers to functions.
 */

 enum temperatures {TOOCOLD, TOOHOT, JUSTRIGHT};
 enum temperatures whichAction;

 const int COLD = 235;
 const int HOT = 260;

 void setup()
 {
    Serial.begin(9600);
    randomSeed(analogRead(0));
 }

void loop()
{
    static void (*funcPtr[])() = {turnUpTemp, turnDownTemp, pourCandy};
    static int iterations = 0;
    int temp;

    temp = readVatTemp();
    whichAction = (enum temperatures) whichOperation(temp);
    (*funcPtr[whichAction])();

    if (iterations++ > 10)
    {
        Serial.println("====================");
        Serial.flush();
        exit(0);
    }
}

/*****
 * Purpose: return a value that determines whether to turn up heat, turn down heat,
 *   or if vat is ready. Pourable candy is between 235 and 260.
 *   
 * Parameters:
 *   int temp       the current vat temperature
 * 
 * Returns:
 *   int            0 = temp too cold, 1 = temp too high, 2 = just right
 *****/
 int whichOperation(int temp)
 {
    Serial.print("temp is ");
    Serial.print(temp);

    if (temp < COLD)
    {
        return TOOCOLD;
    }
    else 
    {
        if (temp > HOT)
        {
            return TOOHOT;
        }
        else
        {
            return JUSTRIGHT;
        }
    }
 }

/*****
 * Purpose: simulate reading a vat's temperature. Values are constrained 100-325 degrees.
 * 
 * Parameters:
 *   void
 * 
 * Returns:
 *   int        the temperature
 *****/
int readVatTemp()
 {
    return random(100, 325);
 }

void turnUpTemp()
{
    Serial.println(" in turnUpTemp()");
}

void turnDownTemp()
{
    Serial.println(" in turnDownTemp()");
}

void pourCandy()
{
    Serial.println(" in pourCandy()");
}
