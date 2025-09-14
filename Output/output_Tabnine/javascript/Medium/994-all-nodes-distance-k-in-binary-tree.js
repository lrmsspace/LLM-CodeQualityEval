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
    const map = new Map();
    const queue = [];
    
    // Build the graph
    function buildGraph(node, parent) {
        if (node) {
            map.set(node.val, parent);
            buildGraph(node.left, node);
            buildGraph(node.right, node);
        }
    }
    
    buildGraph(root, null);
    
    // BFS to find the distance from the target node to each node
    function bfs(node, distance) {
        if (node) {
            queue.push([node, distance]);
            if (distance === k) {
                result.push(node.val);
            }
            bfs(map.get(node.val), distance + 1);
            bfs(node.left, distance + 1);
            bfs(node.right, distance + 1);
        }
    }
    
    const result = [];
    bfs(target, 0);
    return result;
    
};