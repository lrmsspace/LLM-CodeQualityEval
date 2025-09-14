/**https://leetcode.com/problems/binary-tree-cameras/ */
//You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
//Return the minimum number of cameras needed to monitor all nodes of the tree.
// 
//Example 1:
//Input: root = [0,0,null,0,0]
//Output: 1
//Explanation: One camera is enough to monitor all nodes if placed as shown.
//Example 2:
//Input: root = [0,0,null,0,null,0,null,null,0]
//Output: 2
//Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 1000].
//	Node.val == 0
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
 * @return {number}
 */
var minCameraCover = function(root) {
    if (!root) return 0;

    let ans = 0;
    function dfs(node) {
        if (!node) return 2;
        let left = dfs(node.left);
        let right = dfs(node.right);
        if (left === 2 && right === 2) return 0;
        if (left === 0 || right === 0) {
            ans++;
            return 1;
        }
        return 2;
    }

    dfs(root);
    return ans;
};