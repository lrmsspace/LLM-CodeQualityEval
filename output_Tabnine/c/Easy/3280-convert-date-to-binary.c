/*
 You are given a string date representing a Gregorian calendar date in the yyyy-mm-dd format.
 date can be written in its binary representation obtained by converting year, month, and day to their binary representations without any leading zeroes and writing them down in year-month-day format.
 Return the binary representation of date.
 Example 1:
 Input: date = "2080-02-29"
 Output: "100000100000-10-11101"
 Explanation:
 100000100000, 10, and 11101 are the binary representations of 2080, 02, and 29 respectively.
 Example 2:
 Input: date = "1900-01-01"
 Output: "11101101100-1-1"
 Explanation:
 11101101100, 1, and 1 are the binary representations of 1900, 1, and 1 respectively.
 Constraints:
 date.length == 10
 date[4] == date[7] == '-', and all other date[i]'s are digits.
 The input is generated such that date represents a valid Gregorian calendar date between Jan 1st, 1900 and Dec 31st, 2100 (both inclusive).
*/

char* convertDateToBinary(char* date) {
    char* year = strtok(date, "-");
    char* month = strtok(NULL, "-");
    char* day = strtok(NULL, "-");

    char* binaryYear = malloc(sizeof(char) * 17);
    char* binaryMonth = malloc(sizeof(char) * 6);
    char* binaryDay = malloc(sizeof(char) * 6);

    int i;
    for (i = 0; i < 4; i++) {
        binaryYear[i] = (year[i] & 1) + '0';
        year[i] >>= 1;
    }
    binaryYear[4] = '-';
    for (i = 0; i < 2; i++) {
        binaryMonth[i] = (month[i] & 1) + '0';
        month[i] >>= 1;
    }
    binaryMonth[2] = '-';
    for (i = 0; i < 2; i++) {
        binaryDay[i] = (day[i] & 1) + '0';
        day[i] >>= 1;
    }

    char* binaryDate = malloc(sizeof(char) * (strlen(binaryYear) + strlen(binaryMonth) + strlen(binaryDay) + 1));
    strcpy(binaryDate, binaryYear);
    strcat(binaryDate, binaryMonth);
    strcat(binaryDate, binaryDay);

    free(binaryYear);
    free(binaryMonth);
    free(binaryDay);

    return binaryDate;
}
