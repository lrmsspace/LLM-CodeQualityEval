/**https://leetcode.com/problems/palindrome-partitioning-iv/ */
//Given a string s, return true if it is possible to split the string s into three non-empty palindromic substrings. Otherwise, return false.​​​​​
//A string is said to be palindrome if it the same string when reversed.
// 
//Example 1:
//Input: s = "abcbdd"
//Output: true
//Explanation: "abcbdd" = "a" + "bcb" + "dd", and all three substrings are palindromes.
//Example 2:
//Input: s = "bcbddxy"
//Output: false
//Explanation: s cannot be split into 3 palindromes.
// 
//Constraints:
//	3 <= s.length <= 2000
//	s​​​​​​ consists only of lowercase English letters.
/**
 * @param {string} s
 * @return {boolean}
 */
var checkPartitioning = function(s) {
    const n = s.length;
    const dp = Array.from({ length: n }, () => Array(n).fill(false));
    for (let i = 0; i < n; i++) {
        dp[i][i] = true;
        if (i > 0) {
            dp[i - 1][i] = s[i - 1] === s[i];
        }
    }
    for (let len = 3; len <= n; len++) {
        for (let i = 0; i + len - 1 < n; i++) {
            const j = i + len - 1;
            dp[i][j] = s[i] === s[j] && dp[i + 1][j - 1];
        }
    }
    for (let i = 0; i < n - 2; i++) {
        if (dp[0][i]) {
            for (let j = i + 1; j < n - 1; j++) {
                if (dp[i + 1][j] && dp[j + 1][n - 1]) {
                    return true;
                }
            }
        }
    }
    return false;    
};