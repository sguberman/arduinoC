int searchList[200];


void setup() {
    int index;
    int target = 5343;  // part number to find

    Serial.begin(115200);

    memset(searchList, 0, sizeof(searchList));  // clear the array
    searchList[160] = target;  // our target

    index = 0;  // exp1
    while (true) {  // exp2
        if (searchList[index] == target) {
            break;
        }
        index++;  // exp3
    }

    Serial.print("Found target at index = ");
    Serial.println(index);
}

void loop() {
}
