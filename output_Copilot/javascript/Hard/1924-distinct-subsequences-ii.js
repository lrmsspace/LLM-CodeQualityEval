/**https://leetcode.com/problems/distinct-subsequences-ii/ */
//Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo 109 + 7.
//A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not.
// 
//Example 1:
//Input: s = "abc"
//Output: 7
//Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".
//Example 2:
//Input: s = "aba"
//Output: 6
//Explanation: The 6 distinct subsequences are "a", "b", "ab", "aa", "ba", and "aba".
//Example 3:
//Input: s = "aaa"
//Output: 3
//Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".
// 
//Constraints:
//	1 <= s.length <= 2000
//	s consists of lowercase English letters.
/**
 * @param {string} s
 * @return {number}
 */
var distinctSubseqII = function(s) {
    const mod = 1e9 + 7;
    const n = s.length;
    const dp = new Array(n + 1).fill(0);
    const last = new Array(26).fill(-1);

    dp[0] = 1; // Base case: empty string has one subsequence (the empty subsequence)

    for (let i = 1; i <= n; i++) {
        dp[i] = (2 * dp[i - 1]) % mod; // Each subsequence can either include or exclude the current character
        const charIndex = s.charCodeAt(i - 1) - 'a'.charCodeAt(0);
        if (last[charIndex] !== -1) {
            dp[i] = (dp[i] - dp[last[charIndex]] + mod) % mod; // Subtract the count of subsequences that end with the same character
        }
        last[charIndex] = i - 1; // Update the last occurrence of the character
    }

    return (dp[n] - 1 + mod) % mod; // Exclude the empty subsequence    
};