/**https://leetcode.com/problems/longest-subsequence-repeated-k-times/ */
//You are given a string s of length n, and an integer k. You are tasked to find the longest subsequence repeated k times in string s.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
//A subsequence seq is repeated k times in the string s if seq * k is a subsequence of s, where seq * k represents a string constructed by concatenating seq k times.
//	For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of the string "bababcba".
//Return the longest subsequence repeated k times in string s. If multiple such subsequences are found, return the lexicographically largest one. If there is no such subsequence, return an empty string.
// 
//Example 1:
//Input: s = "letsleetcode", k = 2
//Output: "let"
//Explanation: There are two longest subsequences repeated 2 times: "let" and "ete".
//"let" is the lexicographically largest one.
//Example 2:
//Input: s = "bb", k = 2
//Output: "b"
//Explanation: The longest subsequence repeated 2 times is "b".
//Example 3:
//Input: s = "ab", k = 2
//Output: ""
//Explanation: There is no subsequence repeated 2 times. Empty string is returned.
// 
//Constraints:
//	n == s.length
//	2 <= n, k <= 2000
//	2 <= n < k * 8
//	s consists of lowercase English letters.
/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var longestSubsequenceRepeatedK = function(s, k) {
    // Initialize an array dp to store the length of the longest subsequence repeated k times
    const dp = new Array(k + 1).fill(0);
    
    // Iterate through the string s from left to right
    for (let i = 0; i < s.length; i++) {
        // Initialize a variable maxLen to store the maximum length of the subsequence repeated k times
        let maxLen = 0;
        
        // Iterate through the previous dp values and update maxLen
        for (let j = 1; j <= k; j++) {
            if (s[i] === s[i - j]) {
                maxLen = Math.max(maxLen, dp[j - 1]);
            }
        }
        
        // Update the dp value for the current character
        dp[maxLen + 1] = Math.max(dp[maxLen + 1], i + 1);
    }
    
    // Construct the longest subsequence repeated k times
    let result = '';
    for (let i = dp[k]; i >= 0; i--) {
        result = s[i] + result;
    }
    
    return result;
    
};