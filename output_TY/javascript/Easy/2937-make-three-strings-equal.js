/*
 You are given three strings: s1, s2, and s3. In one operation you can choose one of these strings and delete its rightmost character. Note that you cannot completely empty a string.
 Return the minimum number of operations required to make the strings equal. If it is impossible to make them equal, return -1.
 Example 1:
 Input: s1 = "abc", s2 = "abb", s3 = "ab"
 Output: 2
 Explanation: Deleting the rightmost character from both s1 and s2 will result in three equal strings.
 Example 2:
 Input: s1 = "dac", s2 = "bac", s3 = "cac"
 Output: -1
 Explanation: Since the first letters of s1 and s2 differ, they cannot be made equal.
 Constraints:
 1 <= s1.length, s2.length, s3.length <= 100
 s1, s2 and s3 consist only of lowercase English letters.
*/

/**
 * @param {string} s1
 * @param {string} s2
 * @param {string} s3
 * @return {number}
 */
var findMinimumOperations = function(s1, s2, s3) {
    let i = s1.length - 1, j = s2.length - 1, k = s3.length - 1;
    let dp = new Array(s1.length + 1).fill(0).map(() => new Array(s2.length + 1).fill(0).map(() => new Array(s3.length + 1).fill(0)));
    
    while (i >= 0 && j >= 0 && k >= 0) {
        if (s1[i] === s2[j] && s2[j] === s3[k]) {
            dp[i][j][k] = 1 + dp[i + 1][j + 1][k + 1];
        }
    }
    return dp[0][0][0];
    
};