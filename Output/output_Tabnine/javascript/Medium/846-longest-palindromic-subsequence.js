/**https://leetcode.com/problems/longest-palindromic-subsequence/ */
//Given a string s, find the longest palindromic subsequence's length in s.
//A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
// 
//Example 1:
//Input: s = "bbbab"
//Output: 4
//Explanation: One possible longest palindromic subsequence is "bbbb".
//Example 2:
//Input: s = "cbbd"
//Output: 2
//Explanation: One possible longest palindromic subsequence is "bb".
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists only of lowercase English letters.
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindromeSubseq = function(s) {
    const n = s.length;
    const dp = Array.from({length: n}, () => Array(n).fill(0));
    
    // Initialize base cases
    for (let i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    
    // Build up the dp table
    for (let len = 2; len <= n; len++) {
        for (let i = 0; i <= n - len; i++) {
            const j = i + len - 1;
            if (s[i] === s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = Math.max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }
    
    return dp[0][n - 1];
    
};