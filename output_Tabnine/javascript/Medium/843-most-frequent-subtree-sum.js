/**https://leetcode.com/problems/most-frequent-subtree-sum/ */
//Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order.
//The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).
// 
//Example 1:
//Input: root = [5,2,-3]
//Output: [2,-3,4]
//Example 2:
//Input: root = [5,2,-5]
//Output: [2]
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
//	-105 <= Node.val <= 105
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var findFrequentTreeSum = function(root) {
    let sumToCount = new Map();
    let maxFreq = 0;
    let result = [];
    
    function dfs(node) {
        if (!node) return 0;
        
        let leftSum = dfs(node.left);
        let rightSum = dfs(node.right);
        
        let sum = leftSum + rightSum + node.val;
        
        sumToCount.set(sum, (sumToCount.get(sum) || 0) + 1);
        
        maxFreq = Math.max(maxFreq, sumToCount.get(sum));
        
        return sum;
    }
    
    dfs(root);
    
    for (let [sum, freq] of sumToCount.entries()) {
        if (freq === maxFreq) {
            result.push(sum);
        }
    }
    
    return result;
    
};