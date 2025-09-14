/*
 You are given a string s representing a 12-hour format time where some of the digits (possibly none) are replaced with a "?".
 12-hour times are formatted as "HH:MM", where HH is between 00 and 11, and MM is between 00 and 59. The earliest 12-hour time is 00:00, and the latest is 11:59.
 You have to replace all the "?" characters in s with digits such that the time we obtain by the resulting string is a valid 12-hour format time and is the latest possible.
 Return the resulting string.
 Example 1:
 Input: s = "1?:?4"
 Output: "11:54"
 Explanation: The latest 12-hour format time we can achieve by replacing "?" characters is "11:54".
 Example 2:
 Input: s = "0?:5?"
 Output: "09:59"
 Explanation: The latest 12-hour format time we can achieve by replacing "?" characters is "09:59".
 Constraints:
 s.length == 5
 s[2] is equal to the character ":".
 All characters except s[2] are digits or "?" characters.
 The input is generated such that there is at least one time between "00:00" and "11:59" that you can obtain after replacing the "?" characters.
*/

char* findLatestTime(char* s) {
    static char result[6]; // Static to return a pointer to the result
    int hour = 0, minute = 0;

    // Parse the input string
    if (s[0] == '?') {
        hour = 1; // Start with the maximum possible hour
    } else {
        hour = s[0] - '0';
    }
    
    if (s[1] == '?') {
        if (hour < 2) {
            hour = 11; // If hour is less than 2, set to maximum possible hour
        } else {
            hour = 10; // If hour is 2 or more, set to 10
        }
    } else {
        hour = hour * 10 + (s[1] - '0');
    }

    if (s[3] == '?') {
        minute = 5; // Start with the maximum possible minute
    } else {
        minute = s[3] - '0';
    }

    if (s[4] == '?') {
        minute = minute * 10 + 9; // Set last digit of minute to maximum
    } else {
        minute = minute * 10 + (s[4] - '0');
    }

    // Format the result string
    sprintf(result, "%02d:%02d", hour, minute);
    
    return result;
    
}