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
    let count = 0;
    for (let i = 0; i < s.length - 1; i++) {
        if (s[i] === s[i + 1]) {
            count++;
        }
    }
    if (count % 2 === 1) {
        return -1;
    }
    let ans = 0;
    for (let i = 0; i < s.length - 1; i++) {
        if (s[i]!== s[i + 1]) {
            for (let j = i + 1; j < s.length; j++) {
                if (s[j] === s[i + 1]) {
                    [s[i], s[j]] = [s[j], s[i]];
                    ans++;
                    break;
                }
            }
        }
    }
    return ans;
    
};