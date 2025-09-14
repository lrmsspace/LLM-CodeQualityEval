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
    const dp = Array.from({ length: n + 1 }, () => Array(k + 1).fill(Infinity));
    const palin = Array.from({ length: n }, () => Array(n).fill(0));

    for (let i = 0; i < n; i++) {
        palin[i][i] = 0;
        for (let j = i - 1; j >= 0; j--) {
            palin[j][i] = palin[j + 1][i - 1] + (s[j] !== s[i]);
        }
    }

    for (let i = 0; i <= n; i++) {
        dp[i][1] = palin[0][i - 1];
    }

    for (let j = 2; j <= k; j++) {
        for (let i = j - 1; i < n; i++) {
            for (let m = j - 2; m < i; m++) {
                dp[i + 1][j] = Math.min(dp[i + 1][j], dp[m + 1][j - 1] + palin[m + 1][i]);
            }
        }
    }

    return dp[n][k];    
};