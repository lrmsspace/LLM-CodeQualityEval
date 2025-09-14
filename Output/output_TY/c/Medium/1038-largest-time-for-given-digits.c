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
char * largestTimeFromDigits(int* arr, int arrSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[10] = {0};
    for (i = 0; i < arrSize; i++) a[arr[i]]++;
    for (i = 2; i >= 0; i--) {
        for (j = 9; j >= 0; j--) {
            if (a[j] == 0) continue;  
            for (k = 5; k >= 0; k--) {
                if (a[k] == 0) continue;
                for (l = 9; l >= 0; l--) {
                    if (a[l] == 0) continue;
                    for (m = 5; m >= 0; m--) {
                        if (a[m] == 0) continue;
                        for (n = 9; n >= 0; n--) {
                            if (a[n] == 0) continue;    
                            if (a[i] * 10 + a[j] < 24 && a[k] * 10 + a[l] < 60 && a[m] * 10 + a[n] < 60) {
                                return a[i] * 10000 + a[j] * 1000 + a[k] * 100 + a[l] * 10 + a[m] * 1 + a[n] * 0.1;
                            }
                        }
                    }
                }
            } 
        }
    }
    return "00:00";
}