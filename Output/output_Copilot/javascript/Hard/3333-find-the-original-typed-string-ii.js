/*
 Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
 You are given a string word, which represents the final output displayed on Alice's screen. You are also given a positive integer k.
 Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size at least k.
 Since the answer may be very large, return it modulo 109 + 7.
 Example 1:
 Input: word = "aabbccdd", k = 7
 Output: 5
 Explanation:
 The possible strings are: "aabbccdd", "aabbccd", "aabbcdd", "aabccdd", and "abbccdd".
 Example 2:
 Input: word = "aabbccdd", k = 8
 Output: 1
 Explanation:
 The only possible string is "aabbccdd".
 Example 3:
 Input: word = "aaabbb", k = 3
 Output: 8
 Constraints:
 1 <= word.length <= 5 * 105
 word consists only of lowercase English letters.
 1 <= k <= 2000
*/

/**
 * @param {string} word
 * @param {number} k
 * @return {number}
 */
var possibleStringCount = function(word, k) {
    const mod = 1e9 + 7;
    const n = word.length;

    // dp[i][j] represents the number of ways to form a string of length j using the first i characters of word
    const dp = Array.from({ length: n + 1 }, () => Array(k + 1).fill(0));
    dp[0][0] = 1;

    for (let i = 1; i <= n; i++) {
        for (let j = 0; j <= k; j++) {
            // Case 1: Do not use the current character
            dp[i][j] = dp[i - 1][j];

            // Case 2: Use the current character
            for (let l = 1; l <= i; l++) {
                if (j - l >= 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % mod;
                }
            }
        }
    }

    // Sum all valid dp[n][j] for j >= k
    let result = 0;
    for (let j = k; j <= n; j++) {
        result = (result + dp[n][j]) % mod;
    }

    return result;
};