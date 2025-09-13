/**https://leetcode.com/problems/largest-time-for-given-digits/ */
//Given an array arr of 4 digits, find the latest 24-hour time that can be made using each digit exactly once.
//24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59. The earliest 24-hour time is 00:00, and the latest is 23:59.
//Return the latest 24-hour time in "HH:MM" format. If no valid time can be made, return an empty string.
// 
//Example 1:
//Input: arr = [1,2,3,4]
//Output: "23:41"
//Explanation: The valid 24-hour times are "12:34", "12:43", "13:24", "13:42", "14:23", "14:32", "21:34", "21:43", "23:14", and "23:41". Of these times, "23:41" is the latest.
//Example 2:
//Input: arr = [5,5,5,5]
//Output: ""
//Explanation: There are no valid 24-hour times as "55:55" is not valid.
// 
//Constraints:
//	arr.length == 4
//	0 <= arr[i] <= 9
char* largestTimeFromDigits(int* arr, int arrSize) {
    char *res = (char *)malloc(sizeof(char) * 6);
    memset(res, 0, 6);
    
    int max_hour = -1, max_minute = -1;
    for (int i = 0; i < arrSize - 1; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            int hour = 10 * arr[i] + arr[j];
            if (hour >= 24) continue;
            
            int minute = 10 * arr[3 - i] + arr[3 - j];
            if (minute >= 60) continue;
            
            if (hour > max_hour || (hour == max_hour && minute > max_minute)) {
                max_hour = hour;
                max_minute = minute;
            }
        }
    }
    
    if (max_hour == -1) return res;

    sprintf(res, "%02d:%02d", max_hour, max_minute);
    return res;
    
}