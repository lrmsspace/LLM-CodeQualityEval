/**https://leetcode.com/problems/longest-well-performing-interval/ */
//We are given hours, a list of the number of hours worked per day for a given employee.
//A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.
//A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.
//Return the length of the longest well-performing interval.
// 
//Example 1:
//Input: hours = [9,9,6,0,6,6,9]
//Output: 3
//Explanation: The longest well-performing interval is [9,9,6].
//Example 2:
//Input: hours = [6,6,6]
//Output: 0
// 
//Constraints:
//	1 <= hours.length <= 104
//	0 <= hours[i] <= 16
/**
 * @param {number[]} hours
 * @return {number}
 */
var longestWPI = function(hours) {
    let n = hours.length;
    let arr = new Array(n).fill(0);
    for (let i = 0; i < n; i++) {
        if (hours[i] > 8) {
            arr[i] = 1;
        } else {
            arr[i] = -1;
        }
    }
    let map = new Map();
    let sum = 0;
    let res = 0;
    for (let i = 0; i < n; i++) {
        sum += arr[i];
        if (sum > 0) {
            res = i + 1;
        } else {
            if (map.has(sum - 1)) {
                res = Math.max(res, i - map.get(sum - 1));
            }
        }
        if (!map.has(sum)) {
            map.set(sum, i);
        }
    }
    return res;
};