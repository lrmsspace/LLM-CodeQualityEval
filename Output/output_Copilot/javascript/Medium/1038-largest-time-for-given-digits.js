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
/**
 * @param {number[]} arr
 * @return {string}
 */
var largestTimeFromDigits = function(arr) {
    let maxTime = -1;
    for (let i = 0; i < arr.length; i++) {
        for (let j = 0; j < arr.length; j++) {
            for (let k = 0; k < arr.length; k++) {
                if (i === j || i === k || j === k) continue;
                let h = arr[i] * 10 + arr[j];
                let m = arr[k] * 10 + arr[6 - i - j - k];
                if (h < 24 && m < 60) {
                    maxTime = Math.max(maxTime, h * 60 + m);
                }
            }
        }
    }
    if (maxTime === -1) return '';
    let h = Math.floor(maxTime / 60);
    let m = maxTime % 60;
    return `${String(h).padStart(2, '0')}:${String(m).padStart(2, '0')}`;    
};