/**https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/ */
//You are given a 0-indexed string text and another 0-indexed string pattern of length 2, both of which consist of only lowercase English letters.
//You can add either pattern[0] or pattern[1] anywhere in text exactly once. Note that the character can be added even at the beginning or at the end of text.
//Return the maximum number of times pattern can occur as a subsequence of the modified text.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
// 
//Example 1:
//Input: text = "abdcdbc", pattern = "ac"
//Output: 4
//Explanation:
//If we add pattern[0] = 'a' in between text[1] and text[2], we get "abadcdbc". Now, the number of times "ac" occurs as a subsequence is 4.
//Some other strings which have 4 subsequences "ac" after adding a character to text are "aabdcdbc" and "abdacdbc".
//However, strings such as "abdcadbc", "abdccdbc", and "abdcdbcc", although obtainable, have only 3 subsequences "ac" and are thus suboptimal.
//It can be shown that it is not possible to get more than 4 subsequences "ac" by adding only one character.
//Example 2:
//Input: text = "aabb", pattern = "ab"
//Output: 6
//Explanation:
//Some of the strings which can be obtained from text and have 6 subsequences "ab" are "aaabb", "aaabb", and "aabbb".
// 
//Constraints:
//	1 <= text.length <= 105
//	pattern.length == 2
//	text and pattern consist only of lowercase English letters.
/**
 * @param {string} text
 * @param {string} pattern
 * @return {number}
 */
var maximumSubsequenceCount = function(text, pattern) {
    const n = text.length;
    const m = pattern.length;
    
    // Create a 2D dp array to store the maximum number of subsequences ending at each position
    const dp = Array.from({ length: n + 1 }, () => Array.from({ length: m + 1 }, () => 0));
    
    // Initialize the base cases
    dp[0][0] = 1;
    
    // Iterate through the text and pattern to fill the dp array
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= m; j++) {
            // If the current characters match, add the maximum subsequence count ending at the previous position
            if (text[i - 1] === pattern[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                // If the characters do not match, take the maximum subsequence count ending at the previous position
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    // Return the maximum subsequence count
    return dp[n][m];
    
};