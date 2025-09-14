/**https://leetcode.com/problems/unique-binary-search-trees-ii/ */
//Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
// 
//Example 1:
//Input: n = 3
//Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
//Example 2:
//Input: n = 1
//Output: [[1]]
// 
//Constraints:
//	1 <= n <= 8
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
var generateTrees = function(n) {
    if (n === 0) {
        return [];
    }
    
    const result = [];
    
    for (let i = 1; i <= n; i++) {
        const leftTrees = generateTrees(i-1);
        const rightTrees = generateTrees(n-i);
        
        for (const leftTree of leftTrees) {
            for (const rightTree of rightTrees) {
                const root = new TreeNode(i);
                root.left = leftTree;
                root.right = rightTree;
                result.push(root);
            }
        }
    }
    
    return result;
};