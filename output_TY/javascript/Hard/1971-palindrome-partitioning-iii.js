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
    let n = s.length;
    let dp = new Array(n).fill(0).map(() => new Array(k + 1).fill(0));
    let cost = new Array(n).fill(0).map(() => new Array(n).fill(0));
    for (let i = 0; i < n; i++) {
        for (let j = i; j >= 0; j--) {
            if (i == j) {
                cost[i][j] = 0;
            } else {
                cost[i][j] = cost[i - 1][j] + cost[i - 1][i] + 1 - 2 * s[i] ==s[j];
            }
        }
    }
    for (let i = 0; i < n; i++) {
        dp[i][0] = 0;
    }
    for (let k = 1; k <= k; k++) {
        for (let i = 0; i < n; i++) {
            dp[i][k] = Number.MAX_VALUE;
            for (let j = 0; j < i; j++) {
                if (cost[j][i] <= k - 1) {
                    dp[i][k] = Math.min(dp[i][k], dp[j][k - 1] + 1);
                }
            }
        }
    }
    return dp[n - 1][k];
};