/**https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/ */
//You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.
//Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:
//	'L' means to go from a node to its left child node.
//	'R' means to go from a node to its right child node.
//	'U' means to go from a node to its parent node.
//Return the step-by-step directions of the shortest path from node s to node t.
// 
//Example 1:
//Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
//Output: "UURL"
//Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
//Example 2:
//Input: root = [2,1], startValue = 2, destValue = 1
//Output: "L"
//Explanation: The shortest path is: 2 → 1.
// 
//Constraints:
//	The number of nodes in the tree is n.
//	2 <= n <= 105
//	1 <= Node.val <= n
//	All the values in the tree are unique.
//	1 <= startValue, destValue <= n
//	startValue != destValue
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
 * @param {number} startValue
 * @param {number} destValue
 * @return {string}
 */
var getDirections = function(root, startValue, destValue) {
    // Do a DFS to find the start node and the destination node.
    // The DFS function will return the path to the start node and the path to the destination node.
    let startPath = [];
    let destPath = [];
    function dfs(node, val, path) {
        if (!node) return;
        path.push(val);
        if (val === startValue) startPath = path.slice();
        if (val === destValue) destPath = path.slice();
        dfs(node.left, val * 2 + 1, path);
        dfs(node.right, val * 2 + 2, path);
        path.pop();
    }
    dfs(root, 0, []);
    
    // Then generate the instructions.
    let result = '';
    for (let i = 0; i < startPath.length; i++) {
        if (startPath[i] !== destPath[i]) {
            if (startPath[i] < destPath[i]) result += 'U';
            else result += 'D';
            break;
        }
    }
    for (let i = startPath.length - 1; i > destPath.length - 1; i--) {
        result += 'U';
    }
    for (let i = destPath.length - 1; i >= 0; i--) {
        if (destPath[i] % 2 === 0) result += 'L';
        else result += 'R';
    }
    
    return result;
    
};