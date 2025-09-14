/**https://leetcode.com/problems/distinct-subsequences/ */
//Given two strings s and t, return the number of distinct subsequences of s which equals t.
//The test cases are generated so that the answer fits on a 32-bit signed integer.
// 
//Example 1:
//Input: s = "rabbbit", t = "rabbit"
//Output: 3
//Explanation:
//As shown below, there are 3 ways you can generate "rabbit" from s.
//rabbbit
//rabbbit
//rabbbit
//Example 2:
//Input: s = "babgbag", t = "bag"
//Output: 5
//Explanation:
//As shown below, there are 5 ways you can generate "bag" from s.
//babgbag
//babgbag
//babgbag
//babgbag
//babgbag
// 
//Constraints:
//	1 <= s.length, t.length <= 1000
//	s and t consist of English letters.
/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var numDistinct = function(s, t) {
    const dp = Array.from({ length: t.length + 1 }, () => Array(s.length + 1).fill(0));
    for (let j = 0; j <= s.length; j++) {
        dp[0][j] = 1;
    }
    for (let i = 1; i <= t.length; i++) {
        for (let j = 1; j <= s.length; j++) {
            if (t[i - 1] === s[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[t.length][s.length];    
};