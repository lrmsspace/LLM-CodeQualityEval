/*
 You are given a string s and an integer k.
 In one operation, you can replace the character at any position with the next or previous letter in the alphabet (wrapping around so that 'a' is after 'z'). For example, replacing 'a' with the next letter results in 'b', and replacing 'a' with the previous letter results in 'z'. Similarly, replacing 'z' with the next letter results in 'a', and replacing 'z' with the previous letter results in 'y'.
 Return the length of the longest palindromic subsequence of s that can be obtained after performing at most k operations.
 Example 1:
 Input: s = "abced", k = 2
 Output: 3
 Explanation:
 Replace s[1] with the next letter, and s becomes "acced".
 Replace s[4] with the previous letter, and s becomes "accec".
 The subsequence "ccc" forms a palindrome of length 3, which is the maximum.
 Example 2:
 Input: s = "aaazzz", k = 4
 Output: 6
 Explanation:
 Replace s[0] with the previous letter, and s becomes "zaazzz".
 Replace s[4] with the next letter, and s becomes "zaazaz".
 Replace s[3] with the next letter, and s becomes "zaaaaz".
 The entire string forms a palindrome of length 6.
 Constraints:
 1 <= s.length <= 200
 1 <= k <= 200
 s consists of only lowercase English letters.
*/

/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var longestPalindromicSubsequence = function(s, k) {
    // Create a 2D array to store the lengths of longest palindromic subsequences
    const dp = Array.from({ length: s.length }, () => Array(s.length).fill(0));
    
    // Initialize the base cases
    for (let i = 0; i < s.length; i++) {
        dp[i][i] = 1;
    }
    // Iterate over the substring lengths   
    for (let len = 2; len <= s.length; len++) {
        // Iterate over the substrings of length len
        for (let i = 0; i <= s.length - len; i++) {
            const j = i + len - 1;
            
            // If the characters at the start and end of the substring are the same
            if (s[i] === s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                // Choose the maximum length between the two possibilities
                dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    
    // Calculate the maximum length of a palindromic subsequence that can be obtained after k operations
    let maxLength = 0;
    for (let i = 0; i < s.length; i++) {    
        for (let j = i; j < s.length; j++) {
            const length = dp[i][j];
            if (length > maxLength && k >= length - 1) {
                maxLength = length;
            }
        }
    }   
    return maxLength;   
    
};