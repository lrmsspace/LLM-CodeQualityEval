/**https://leetcode.com/problems/unique-binary-search-trees/ */
//Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
// 
//Example 1:
//Input: n = 3
//Output: 5
//Example 2:
//Input: n = 1
//Output: 1
// 
//Constraints:
//	1 <= n <= 19
/**
 * @param {number} n
 * @return {number}
 */
var numTrees = function(n) {
    let dp = new Array(n + 1).fill(0);
    dp[0] = 1;
    dp[1] = 1;
    for (let i = 2; i <= n; i++) {
        for (let j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
};