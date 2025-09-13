/**https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/ */
//Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
//Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
// 
//Example 1:
//Input: root = [1,7,0,7,-8,null,null]
//Output: 2
//Explanation: 
//Level 1 sum = 1.
//Level 2 sum = 7 + 0 = 7.
//Level 3 sum = 7 + -8 = -1.
//So we return the level with the maximum sum which is level 2.
//Example 2:
//Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
//Output: 2
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
 * @return {number}
 */
var maxLevelSum = function(root) {
    if (!root) return 0; // If the tree is empty, return 0

    let queue = [root]; // Initialize a queue for level order traversal
    let maxSum = -Infinity; // Initialize maxSum to negative infinity
    let minLevel = 1; // Initialize minLevel to 1

    let level = 1; // Start from level 1

    while (queue.length) {
        let levelSize = queue.length; // Number of nodes at the current level
        let currentSum = 0; // Sum of values at the current level

        for (let i = 0; i < levelSize; i++) {
            let node = queue.shift(); // Dequeue the front node
            currentSum += node.val; // Add its value to the current sum

            if (node.left) queue.push(node.left); // Enqueue left child if exists
            if (node.right) queue.push(node.right); // Enqueue right child if exists
        }

        // Update maxSum and minLevel if currentSum is greater than maxSum
        if (currentSum > maxSum) {
            maxSum = currentSum;
            minLevel = level;
        }

        level++; // Move to the next level
    }

    return minLevel; // Return the level with the maximum sum  
};