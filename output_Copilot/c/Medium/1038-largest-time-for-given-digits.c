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
    int i, j, k, l, max = -1;
    char *res = (char *)malloc(6);
    for (i = 0; i < arrSize; i++) {
        for (j = 0; j < arrSize; j++) {
            if (j == i) continue;
            for (k = 0; k < arrSize; k++) {
                if (k == i || k == j) continue;
                l = 6 - i - j - k;
                int hour = arr[i] * 10 + arr[j];
                int minute = arr[k] * 10 + arr[l];
                if (hour < 24 && minute < 60) {
                    int time = hour * 60 + minute;
                    if (time > max) {
                        max = time;
                        sprintf(res, "%d%d:%d%d", arr[i], arr[j], arr[k], arr[l]);
                    }
                }
            }
        }
    }
    return max == -1 ? "" : res;    
}