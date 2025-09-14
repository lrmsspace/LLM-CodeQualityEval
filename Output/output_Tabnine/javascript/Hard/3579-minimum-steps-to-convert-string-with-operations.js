/*
 You are given two strings, word1 and word2, of equal length. You need to transform word1 into word2.
 For this, divide word1 into one or more contiguous substrings. For each substring substr you can perform the following operations:
 Replace: Replace the character at any one index of substr with another lowercase English letter.
 Swap: Swap any two characters in substr.
 Reverse Substring: Reverse substr.
 Each of these counts as one operation and each character of each substring can be used in each type of operation at most once (i.e. no single index may be involved in more than one replace, one swap, or one reverse).
 Return the minimum number of operations required to transform word1 into word2.
 Example 1:
 Input: word1 = "abcdf", word2 = "dacbe"
 Output: 4
 Explanation:
 Divide word1 into "ab", "c", and "df". The operations are:
 For the substring "ab",
 Perform operation of type 3 on "ab" -> "ba".
 Perform operation of type 1 on "ba" -> "da".
 For the substring "c" do no operations.
 For the substring "df",
 Perform operation of type 1 on "df" -> "bf".
 Perform operation of type 1 on "bf" -> "be".
 Example 2:
 Input: word1 = "abceded", word2 = "baecfef"
 Output: 4
 Explanation:
 Divide word1 into "ab", "ce", and "ded". The operations are:
 For the substring "ab",
 Perform operation of type 2 on "ab" -> "ba".
 For the substring "ce",
 Perform operation of type 2 on "ce" -> "ec".
 For the substring "ded",
 Perform operation of type 1 on "ded" -> "fed".
 Perform operation of type 1 on "fed" -> "fef".
 Example 3:
 Input: word1 = "abcdef", word2 = "fedabc"
 Output: 2
 Explanation:
 Divide word1 into "abcdef". The operations are:
 For the substring "abcdef",
 Perform operation of type 3 on "abcdef" -> "fedcba".
 Perform operation of type 2 on "fedcba" -> "fedabc".
 Constraints:
 1 <= word1.length == word2.length <= 100
 word1 and word2 consist only of lowercase English letters.
*/

/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minOperations = function(word1, word2) {

    // Initialize a 2D array dp to store the minimum number of operations required for transforming word1[0...i] into word2[0...j]
    var dp = Array(word1.length + 1).fill(null).map(() => Array(word2.length + 1).fill(0));
    
    // Initialize the base case
    for (var i = 0; i <= word1.length; i++) {
        dp[i][0] = i;
    }
    for (var j = 0; j <= word2.length; j++) {
        dp[0][j] = j;
    }
    // Fill the dp table
    for (var i = 1; i <= word1.length; i++) {
        for (var j = 1; j <= word2.length; j++) {
            if (word1[i - 1] === word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = Math.min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
    }
    
    // Return the minimum number of operations required
    return dp[word1.length][word2.length];
    
};