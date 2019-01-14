/*****
  Purpose: Determine if a given year is a leap year

  Parameters:
    int year        The year to test

  Return value:
    int             1 if leap year, 0 otherwise
*****/
int isLeapYear(int year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        return 1;  // leap year
    } else {
        return 0;  // not a leap year
    }
}