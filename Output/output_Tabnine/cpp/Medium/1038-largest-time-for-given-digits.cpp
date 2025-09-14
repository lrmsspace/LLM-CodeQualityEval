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
class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), greater<int>());
        string res = "";
        for (int h1 = arr[0]; h1 <= 2; h1++) {
            for (int h2 = 0; h2 <= 5; h2++) {
                for (int m1 = arr[1]; m1 <= 5; m1++) {
                    for (int m2 = 0; m2 <= 9; m2++) {
                        if (h1 * 10 + h2 <= 23 && m1 * 10 + m2 <= 59) {
                            res = to_string(h1 * 10 + h2) + ":" + to_string(m1 * 10 + m2);
                            return res;
                        }
                    }
                }
            }
        }
        return res; // No valid time found, return an empty string.
        
    }
};