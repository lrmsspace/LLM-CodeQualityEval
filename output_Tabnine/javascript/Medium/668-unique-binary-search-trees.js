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
    // Dynamic Programming
    // dp[i] represents the number of unique BST's with i nodes
    const dp = new Array(n + 1).fill(0);
    dp[0] = 1; // base case: 0 nodes gives 1 BST
    
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= i; j++) {
            // For each node, consider it as the root
            // The left subtree has j-1 nodes, and the right subtree has i-j nodes
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    
    return dp[n];
    
};