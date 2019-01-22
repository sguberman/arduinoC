#include <EEPROM.h>

#define DEBUG 1

const int MAXPEOPLE = 10;

struct servicePeople
{
    int ID;
    char Name[20];
    char PW[10];
    long Phone;
};

union servicePeopleUnion
{
    byte temp[sizeof(int)];
    int testID;
    struct servicePeople testServicePeople;
} myUnion;

servicePeople myPeople[MAXPEOPLE] = {
    {0, "This is a dummy", "admin", 5555555},
    {101, "Kack Lawn Service", "Clowder", 2345678},
    {222, "Jane's Plants", "Noah", 4202513},
    {333, "Terrys Pool Service", "Billings", 4301016}
};

void dataDump(struct servicePeople temp);
int findEepromTop();
int readInitFlag();
void readOneRecord(int index);
void writeFirstRecord();
void writeOneRecord(int index);

int loopCounter = 0;
int initFlag = 0;
struct servicePeople temp;

void setup()
{
    int eepromMax;
    int i;

    Serial.begin(9600);
    
    eepromMax = findEepromTop();
    #ifdef DEBUG
        Serial.print("eepromMax = ");
        Serial.println(eepromMax);
    #endif

    initFlag = readInitFlag();
    initFlag = 0;  // comment this line out after first run
    if (initFlag == 0)
    {
        for (i = 0; i < MAXPEOPLE; i++)
        {
            writeOneRecord(i);
        }
    }
    initFlag = 1;
}

int findEepromTop()
{
    return E2END + 1;
}

int readInitFlag()
{
    int i;
    for (i = 0; i < sizeof(int); i++)
    {
        myUnion.temp[i] = EEPROM.read(i);
    }
    return myUnion.testID;
}
