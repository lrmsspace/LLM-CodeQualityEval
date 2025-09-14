/**https://leetcode.com/problems/distinct-echo-substrings/ */
//Return the number of distinct non-empty substrings of text that can be written as the concatenation of some string with itself (i.e. it can be written as a + a where a is some string).
// 
//Example 1:
//Input: text = "abcabcabc"
//Output: 3
//Explanation: The 3 substrings are "abcabc", "bcabca" and "cabcab".
//Example 2:
//Input: text = "leetcodeleetcode"
//Output: 2
//Explanation: The 2 substrings are "ee" and "leetcodeleetcode".
// 
//Constraints:
//	1 <= text.length <= 2000
//	text has only lowercase English letters.
/**
 * @param {string} text
 * @return {number}
 */
var distinctEchoSubstrings = function(text) {
    let n = text.length;
    let count = 0;
    let dp = Array(n).fill(false).map(() => Array(n).fill(false));
    
    for (let i = n - 1; i >= 0; i--) {
        for (let j = i + 1; j < n; j++) {
            if (text[i] === text[j]) {
                dp[i][j] = (j - i === 1) || dp[i + 1][j - 1];
                if (dp[i][j]) {
                    count += j - i + 1;
                }
            }
        }
    }
    
    return count / 2; // divide by 2 to avoid counting each substring twice
    
};