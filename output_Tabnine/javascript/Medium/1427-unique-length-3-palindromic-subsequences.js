/**https://leetcode.com/problems/unique-length-3-palindromic-subsequences/ */
//Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
//Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.
//A palindrome is a string that reads the same forwards and backwards.
//A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
//	For example, "ace" is a subsequence of "abcde".
// 
//Example 1:
//Input: s = "aabca"
//Output: 3
//Explanation: The 3 palindromic subsequences of length 3 are:
//- "aba" (subsequence of "aabca")
//- "aaa" (subsequence of "aabca")
//- "aca" (subsequence of "aabca")
//Example 2:
//Input: s = "adc"
//Output: 0
//Explanation: There are no palindromic subsequences of length 3 in "adc".
//Example 3:
//Input: s = "bbcbaba"
//Output: 4
//Explanation: The 4 palindromic subsequences of length 3 are:
//- "bbb" (subsequence of "bbcbaba")
//- "bcb" (subsequence of "bbcbaba")
//- "bab" (subsequence of "bbcbaba")
//- "aba" (subsequence of "bbcbaba")
// 
//Constraints:
//	3 <= s.length <= 105
//	s consists of only lowercase English letters.
/**
 * @param {string} s
 * @return {number}
 */
var countPalindromicSubsequence = function(s) {
    const n = s.length;
    const dp = Array.from({ length: n + 1 }, () => Array(n + 1).fill(0));
    
    for (let i = n - 1; i >= 0; i--) {
        for (let j = i + 1; j <= n; j++) {
            if (s[i] === s[j - 1]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    
    let count = 0;
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            for (let k = j + 1; k <= n; k++) {
                if (dp[i][j] === k - i && dp[j][k] === k - j) {
                    count++;
                }
            }
        }
    }
    
    return count;
    
};