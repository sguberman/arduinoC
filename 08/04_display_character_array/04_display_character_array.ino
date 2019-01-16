void setup()
{
    char greet[6];
    char *ptr;
    int i;
    
    Serial.begin(9600);
    
    greet[0] = 'H';
    greet[1] = 'e';
    greet[2] = 'l';
    greet[3] = 'l';
    greet[4] = 'o';
    greet[5] = '\0';
    
    ptr = greet;
    for (i = 0; i < 5; i++)
    {
        // All four lines do the same thing because
        // using an array name by itself is the same as using the lvalue
        
        //Serial.print(greet[i]);
        //Serial.print(*(greet + i));
        //Serial.print(*(greet + i * sizeof(char)));
        Serial.print(*ptr++);
    }
    
    // Another way that works because *ptr evaluates to false
    // once it hits the null termination character
    ptr = greet;
    while (*ptr)
    {
        Serial.print(*ptr++);
    }
    
    // Or do it the natural way
    // Serial.print takes the lvalue of the array and
    // reads until it reaches a null termination character
    Serial.print(greet);
    // If greet did not have a '\0' at the end, we would keep
    // going until a 0 is reached.
}

void loop() {}