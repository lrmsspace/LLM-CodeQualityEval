/**https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/ */
//Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
//You can return the answer in any order.
// 
//Example 1:
//Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
//Output: [7,4,1]
//Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
//Example 2:
//Input: root = [1], target = 1, k = 3
//Output: []
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 500].
//	0 <= Node.val <= 500
//	All the values Node.val are unique.
//	target is the value of one of the nodes in the tree.
//	0 <= k <= 1000
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} target
 * @param {number} k
 * @return {number[]}
 */
var distanceK = function(root, target, k) {
    let ans = [];
    let map = new Map();
    let visited = new Set();
    
    function dfs(node, parent) {
        if (!node) return;
        map.set(node, parent);
        dfs(node.left, node);
        dfs(node.right, node);
    }
    
    dfs(root, null);
    
    function bfs(node, dist) {
        if (!node || visited.has(node)) return;
        visited.add(node);
        if (dist === k) {
            ans.push(node.val);
            return;
        }
        bfs(map.get(node), dist + 1);
        bfs(node.left, dist + 1);
        bfs(node.right, dist + 1);
    }
    
    bfs(target, 0);
    return ans;    
};