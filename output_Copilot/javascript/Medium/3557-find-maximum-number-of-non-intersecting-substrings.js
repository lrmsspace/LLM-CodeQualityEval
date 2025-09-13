/*
 You are given a string word.
 Return the maximum number of non-intersecting substrings of word that are at least four characters long and start and end with the same letter.
 Example 1:
 Input: word = "abcdeafdef"
 Output: 2
 Explanation:
 The two substrings are "abcdea" and "fdef".
 Example 2:
 Input: word = "bcdaaaab"
 Output: 1
 Explanation:
 The only substring is "aaaa". Note that we cannot also choose "bcdaaaab" since it intersects with the other substring.
 Constraints:
 1 <= word.length <= 2 * 105
 word consists only of lowercase English letters.
*/

/**
 * @param {string} word
 * @return {number}
 */
var maxSubstrings = function(word) {
    const n = word.length;
    const dp = new Array(n + 1).fill(0);
    const lastOccurrence = new Map();

    for (let i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        const currChar = word[i - 1];
        if (lastOccurrence.has(currChar)) {
            const prevIndex = lastOccurrence.get(currChar);
            if (i - prevIndex >= 4) {
                dp[i] = Math.max(dp[i], dp[prevIndex] + 1);
            }
        }
        lastOccurrence.set(currChar, i);
    }

    return dp[n];
};