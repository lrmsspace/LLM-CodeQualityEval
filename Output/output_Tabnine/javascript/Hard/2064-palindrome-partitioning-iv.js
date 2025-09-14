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
    const dp = Array.from({ length: n + 1 }, () => Array(n + 1).fill(false));
    
    // Check if substring is palindrome
    for (let i = 0; i < n; i++) {
        dp[i][i] = true;
        for (let j = i + 1; j < n; j++) {
            dp[i][j] = s[i] === s[j] && (j - i <= 2 || dp[i + 1][j - 1]);
        }
    }
    
    // Check if it is possible to partition s into three non-empty palindromic substrings
    for (let len = 3; len <= n; len++) {
        for (let i = 0; i <= n - len; i++) {
            const j = i + len - 1;
            if (dp[i + 1][j - 1] && dp[i][j - len + 2]) {
                return true;
            }
        }
    }
    
    return false;
    
};