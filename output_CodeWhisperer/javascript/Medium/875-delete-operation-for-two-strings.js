/**https://leetcode.com/problems/delete-operation-for-two-strings/ */
//Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
//In one step, you can delete exactly one character in either string.
// 
//Example 1:
//Input: word1 = "sea", word2 = "eat"
//Output: 2
//Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
//Example 2:
//Input: word1 = "leetcode", word2 = "etco"
//Output: 4
// 
//Constraints:
//	1 <= word1.length, word2.length <= 500
//	word1 and word2 consist of only lowercase English letters.
/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function(word1, word2) {
    let m = word1.length;
    let n = word2.length;
    let dp = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    for (let i = 0; i <= m; i++) {
        for (let j = 0; j <= n; j++) {
            if (i === 0) {
                dp[i][j] = j;
            } else if (j === 0) {
                dp[i][j] = i;
            } else if (word1[i - 1] === word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + Math.min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
};