#define AND 1
#define OR 2
#define XOR 3
#define NOT 4

#define COMMA ","

#define ARRAYLENGTH(x) (sizeof(x) / sizeof(x[0]))

int getBitwiseParameters(int *which, int *op1, int *op2);

int ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11};

void setup()
{
    Serial.begin(9600);
    for (int i = 0; i < ARRAYLENGTH(ledPin); i++)
    {
        pinMode(ledPin[i], OUTPUT);
    }
    Serial.println("Bitwise Operators: 1 = AND, 2 = OR, 3 = XOR, 4 = NOT");
    Serial.println("Enter Bitwise Operator COMMA Operand 1 COMMA Operand 2");
    Serial.println("  Ex: 1,23,52 will compute bitwise AND of 23 and 52");
}

void loop()
{
    int whichOperator = 0;
    int operand1;
    int operand2;

    getBitwiseParameters(&whichOperator, &operand1, &operand2);
    if (whichOperator)
    {
        showResult(whichOperator, operand1, operand2);
        whichOperator = operand1 = operand2 = 0;
    }
}

void showResult(int which, int op1, int op2)
{
    byte result;

    switch (which)
    {
        case AND:
            result = op1 & op2;
            break;
        case OR:
            result = op1 | op2;
            break;
        case XOR:
            result = op1 ^ op2;
            break;
        case NOT:
            result = ~op1;
            break;
        default:
            break;
    }

    displayBinary((byte) op1);
    delay(1000);
    displayBinary((byte) op2);
    delay(1000);
    displayBinary(result);
}

int getBitwiseParameters(int *which, int *op1, int *op2)
{
    char buff[10];
    char *ptr;
    int charsRead;
    int temp;

    if (Serial.available())
    {
        charsRead = Serial.readBytesUntil('\n', buff, 9);
    }
    buff[charsRead] = NULL;  // make a str
    
    ptr = strtok(buff, COMMA);
    *which = atoi(buff);
    ptr = strtok(NULL, COMMA);  // use internal ptr
    *op1 = atoi(ptr);
    ptr = strtok(NULL, COMMA);
    *op2 = atoi(ptr);
}

void displayBinary(byte num)
{
    for (int i = 0; i < ARRAYLENGTH(ledPin); i++)
    {
        digitalWrite(ledPin[i], bitRead(num, i));
    }
}
