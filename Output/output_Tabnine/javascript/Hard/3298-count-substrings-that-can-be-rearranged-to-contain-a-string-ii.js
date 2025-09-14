/*
 You are given two strings word1 and word2.
 A string x is called valid if x can be rearranged to have word2 as a prefix.
 Return the total number of valid substrings of word1.
 Note that the memory limits in this problem are smaller than usual, so you must implement a solution with a linear runtime complexity.
 Example 1:
 Input: word1 = "bcca", word2 = "abc"
 Output: 1
 Explanation:
 The only valid substring is "bcca" which can be rearranged to "abcc" having "abc" as a prefix.
 Example 2:
 Input: word1 = "abcabc", word2 = "abc"
 Output: 10
 Explanation:
 All the substrings except substrings of size 1 and size 2 are valid.
 Example 3:
 Input: word1 = "abcabc", word2 = "aaabc"
 Output: 0
 Constraints:
 1 <= word1.length <= 106
 1 <= word2.length <= 104
 word1 and word2 consist only of lowercase English letters.
*/

/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var validSubstringCount = function(word1, word2) {
    const n = word1.length;
    const m = word2.length;
    
    if (n < m) return 0;
    
    const dp = Array(n + 1).fill(0);
    let count = 0;
    
    for (let i = 1; i <= n; i++) {
        for (let j = Math.max(0, i - m); j < i; j++) {
            if (word1.slice(j, i) === word2) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
                count += dp[i];
            }
        }
    }
    
    return count;
    
};