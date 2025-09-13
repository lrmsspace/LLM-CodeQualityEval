/**https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/ */
//Given a binary string s, return the minimum number of character swaps to make it alternating, or -1 if it is impossible.
//The string is called alternating if no two adjacent characters are equal. For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
//Any two characters may be swapped, even if they are not adjacent.
// 
//Example 1:
//Input: s = "111000"
//Output: 1
//Explanation: Swap positions 1 and 4: "111000" -> "101010"
//The string is now alternating.
//Example 2:
//Input: s = "010"
//Output: 0
//Explanation: The string is already alternating, no swaps are needed.
//Example 3:
//Input: s = "1110"
//Output: -1
// 
//Constraints:
//	1 <= s.length <= 1000
//	s[i] is either '0' or '1'.
/**
 * @param {string} s
 * @return {number}
 */
var minSwaps = function(s) {
    let n = s.length;
    let count1 = 0;
    let count2 = 0;
    for (let i = 0; i < n; i++) {
        if (s[i] === '1') {
            count1++;
        } else {
            count2++;
        }
    }
    if (Math.abs(count1 - count2) > 1) {
        return -1;
    }
    let swaps1 = 0;
    let swaps2 = 0;
    for (let i = 0; i < n; i++) {
        if (s[i] !== '0' && i % 2 === 0) {
            swaps1++;
        }
        if (s[i] !== '1' && i % 2 === 1) {
            swaps1++;
        }
        if (s[i] !== '1' && i % 2 === 0) {
            swaps2++;
        }
        if (s[i] !== '0' && i % 2 === 1) {
            swaps2++;
        }
    }
    return Math.min(Math.ceil(swaps1 / 2), Math.ceil(swaps2 / 2));    
};