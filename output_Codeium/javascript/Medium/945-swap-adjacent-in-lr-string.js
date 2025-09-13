/**https://leetcode.com/problems/swap-adjacent-in-lr-string/ */
//In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string result, return True if and only if there exists a sequence of moves to transform start to result.
// 
//Example 1:
//Input: start = "RXXLRXRXL", result = "XRLXXRRLX"
//Output: true
//Explanation: We can transform start to result following these steps:
//RXXLRXRXL ->
//XRXLRXRXL ->
//XRLXRXRXL ->
//XRLXXRRXL ->
//XRLXXRRLX
//Example 2:
//Input: start = "X", result = "L"
//Output: false
// 
//Constraints:
//	1 <= start.length <= 104
//	start.length == result.length
//	Both start and result will only consist of characters in 'L', 'R', and 'X'.
/**
 * @param {string} start
 * @param {string} result
 * @return {boolean}
 */
var canTransform = function(start, result) {
    let i = 0, j = 0;
    while (i < start.length && j < result.length) {
        if (start[i] === result[j]) {
            i++;
            j++;
        } else if (start[i] === 'X' && start[i+1] === result[j]) {
            i += 2;
            j++;
        } else if (start[i] === 'R' && start[i-1] === 'X' && start[i-1] === result[j]) {
            i++;
            j++;
        } else if (start[i] === 'L' && start[i+1] === 'X' && start[i+2] === result[j]) {
            i += 2;
            j++;
        } else return false;
    }
    return i === start.length && j === result.length;
};