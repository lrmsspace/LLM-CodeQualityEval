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
    let dp = Array(s.length).fill(0).map(() => Array(s.length).fill(0));
    for (let i = 0; i < s.length; i++) {
        dp[i][i] = 0;
    }
    for (let length = 2; length <= s.length; length++) {
        for (let i = 0; i <= s.length - length; i++) {
            let j = i + length - 1;
            if (s[i] === s[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = 1 + Math.min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][s.length - 1] - (k - 1);
};