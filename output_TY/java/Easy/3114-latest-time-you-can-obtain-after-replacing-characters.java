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
    public String findLatestTime(String s) {
        int[] count = new int[10];
        for (char c : s.toCharArray()) {
            if (c != '?') {
                count[c - '0']++;
            }
        }
        
        int[] max = new int[10];
        for (int i = 9; i >= 0; i--) {
            max[i] = Math.min(count[i], 2);
            count[i] -= max[i];
        }
        
        int[] min = new int[10];
        for (int i = 0; i < 10; i++) {
            min[i] = Math.min(count[i], 1);
            count[i] -= min[i];
        }
        return max[0] + max[1] + min[2] + min[4] + min[5] + min[6] + min[8];
        
    }
}