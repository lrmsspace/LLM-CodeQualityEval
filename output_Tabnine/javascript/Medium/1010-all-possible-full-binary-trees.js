/**https://leetcode.com/problems/all-possible-full-binary-trees/ */
//Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.
//Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.
//A full binary tree is a binary tree where each node has exactly 0 or 2 children.
// 
//Example 1:
//Input: n = 7
//Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
//Example 2:
//Input: n = 3
//Output: [[0,0,0]]
// 
//Constraints:
//	1 <= n <= 20
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number} n
 * @return {TreeNode[]}
 */
var allPossibleFBT = function(n) {
    if (n % 2 === 0) return [];
    let dp = Array(n + 1).fill(null).map(() => new Array(n + 1).fill(null));
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= i; j++) {
            dp[i][j] = [];
            for (let k = 1; k < i; k++) {
                dp[i][j] = dp[i][j].concat(
                    dp[j - 1].flatMap(left =>
                        dp[i - j - 1].map(right => new TreeNode(0, left, right))
                    )
                );
            }
        }
    }
    return dp[n][n];
    
};