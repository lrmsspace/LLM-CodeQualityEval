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

class Solution {
public:
    string findLatestTime(string s) {

        // Find the index of the first "?" character
        int index = s.find('?');
        if (index == string::npos) {
            return s;  // No "?" characters found, return the original string as it is
        }
        // Replace the "?" character with the largest possible digit
        s[index] = '9';
        // Check if the resulting time is valid
        while (index > 0 && s[index - 1] == '9') {
            s[index - 1] = '0';
            index--;
        }
        // If the resulting time is still invalid, replace the last "?" character with the largest possible digit
        if (index == 0 && s[index] == '9') {
            s[index] = '0';
        }
        return s;  // Return the resulting string with the latest possible time
        
    }
};