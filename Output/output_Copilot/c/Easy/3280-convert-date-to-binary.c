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
    int year, month, day;
    sscanf(date, "%d-%d-%d", &year, &month, &day); // Parse the date string

    // Convert year, month, and day to binary strings
    char* binaryYear = (char*)malloc(12 * sizeof(char)); // 11 bits for year (up to 2100)
    char* binaryMonth = (char*)malloc(4 * sizeof(char)); // 3 bits for month (1-12)
    char* binaryDay = (char*)malloc(6 * sizeof(char)); // 5 bits for day (1-31)

    sprintf(binaryYear, "%b", year);
    sprintf(binaryMonth, "%b", month);
    sprintf(binaryDay, "%b", day);

    // Concatenate the binary strings with '-' in between
    char* result = (char*)malloc(20 * sizeof(char)); // Enough space for the result
    sprintf(result, "%s-%s-%s", binaryYear, binaryMonth, binaryDay);

    // Free allocated memory
    free(binaryYear);
    free(binaryMonth);
    free(binaryDay);

    return result; // Return the final binary representation    
    
}