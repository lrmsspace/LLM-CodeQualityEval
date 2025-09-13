/**https://leetcode.com/problems/palindrome-partitioning-iii/ */
//You are given a string s containing lowercase letters and an integer k. You need to :
//	First, change some characters of s to other lowercase English letters.
//	Then divide s into k non-empty disjoint substrings such that each substring is a palindrome.
//Return the minimal number of characters that you need to change to divide the string.
// 
//Example 1:
//Input: s = "abc", k = 2
//Output: 1
//Explanation: You can split the string into "ab" and "c", and change 1 character in "ab" to make it palindrome.
//Example 2:
//Input: s = "aabbc", k = 3
//Output: 0
//Explanation: You can split the string into "aa", "bb" and "c", all of them are palindrome.
//Example 3:
//Input: s = "leetcode", k = 8
//Output: 0
// 
//Constraints:
//	1 <= k <= s.length <= 100.
//	s only contains lowercase English letters.
/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var palindromePartition = function(s, k) {
    const n = s.length;
    const dp = Array(n + 1).fill(0).map(() => Array(k + 1).fill(Infinity));
    
    // Initialize base cases
    for (let i = 0; i <= n; i++) {
        dp[i][1] = i;
    }
    
    // Build up the dp table
    for (let i = 2; i <= n; i++) {
        for (let j = 2; j <= k && j <= i; j++) {
            for (let l = 0; l < i - j + 1; l++) {
                const r = l + j - 1;
                if (s[l] === s[r] && dp[l + 1][j - 1] === r - l) {
                    dp[i][j] = Math.min(dp[i][j], dp[l][j - 1]);
                }
            }
            dp[i][j] += 1;
        }
    }
    
    return dp[n][k];
    
};