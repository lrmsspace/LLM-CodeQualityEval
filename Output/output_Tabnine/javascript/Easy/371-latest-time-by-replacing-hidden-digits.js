/**https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/ */
//You are given a string time in the form of  hh:mm, where some of the digits in the string are hidden (represented by ?).
//The valid times are those inclusively between 00:00 and 23:59.
//Return the latest valid time you can get from time by replacing the hidden digits.
// 
//Example 1:
//Input: time = "2?:?0"
//Output: "23:50"
//Explanation: The latest hour beginning with the digit '2' is 23 and the latest minute ending with the digit '0' is 50.
//Example 2:
//Input: time = "0?:3?"
//Output: "09:39"
//Example 3:
//Input: time = "1?:22"
//Output: "19:22"
// 
//Constraints:
//	time is in the format hh:mm.
//	It is guaranteed that you can produce a valid time from the given string.
/**
 * @param {string} time
 * @return {string}
 */
var maximumTime = function(time) {
    let arr = time.split(':');
    let h = arr[0], m = arr[1];
    
    if (h[0] === '?') {
        h = h[1] === '2'? '2' : '1';
    }
    if (h[1] === '?') {
        h = h[0] === '2'? '23' : '22';
    }
    
    if (m[0] === '?') {
        m = m[1] === '5'? '5' : '9';
    }
    if (m[1] === '?') {
        m = m[0] === '5'? '59' : '50';
    }
    
    return h + ':' + m;
    
};