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
    let n = s.length;
    let dp = new Array(n).fill(0).map(() => new Array(n).fill(0));
    for (let i = n - 1; i >= 0; i--) {
        for (let j = i; j < n; j++) {
            if (s[i] === s[j]) {
                if (i + 1 > j - 1 || dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                }
            }
        }
    }
    for (let i = 0; i < n - 2; i++) {
        for (let j = i + 1; j < n -1; j++) {
            if (dp[i][j] && dp[j + 1][n - 1]) {
                return false;
            }
        }
    }
    return true;
};