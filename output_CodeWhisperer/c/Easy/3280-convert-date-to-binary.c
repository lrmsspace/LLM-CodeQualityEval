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
    int year = 0, month = 0, day = 0;
    sscanf(date, "%d-%d-%d", &year, &month, &day);
    
    char* binaryYear = (char*)malloc(17 * sizeof(char));
    char* binaryMonth = (char*)malloc(5 * sizeof(char));
    char* binaryDay = (char*)malloc(6 * sizeof(char));
    
    int i;
    for (i = 0; i < 16; i++) {
        binaryYear[i] = (year & (1 << (15 - i))) ? '1' : '0';
    }
    binaryYear[16] = '\0';
    
    for (i = 0; i < 4; i++) {
        binaryMonth[i] = (month & (1 << (3 - i))) ? '1' : '0';
    }
    binaryMonth[4] = '\0';
    
    for (i = 0; i < 5; i++) {
        binaryDay[i] = (day & (1 << (4 - i))) ? '1' : '0';
    }
    binaryDay[5] = '\0';
    
    char* result = (char*)malloc(30 * sizeof(char));
    sprintf(result, "%s-%s-%s", binaryYear, binaryMonth, binaryDay);
    
    free(binaryYear);
    free(binaryMonth);
    free(binaryDay);
    
    return result;    
}