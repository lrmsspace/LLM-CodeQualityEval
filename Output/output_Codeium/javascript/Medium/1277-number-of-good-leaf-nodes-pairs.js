/**https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/ */
//You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.
//Return the number of good leaf node pairs in the tree.
// 
//Example 1:
//Input: root = [1,2,3,null,4], distance = 3
//Output: 1
//Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.
//Example 2:
//Input: root = [1,2,3,4,5,6,7], distance = 3
//Output: 2
//Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.
//Example 3:
//Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
//Output: 1
//Explanation: The only good pair is [2,5].
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 210].
//	1 <= Node.val <= 100
//	1 <= distance <= 10
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
 * @param {number} distance
 * @return {number}
 */
var countPairs = function(root, distance) {
    let count = 0;
    const dfs = (node, depth) => {
        if (!node) return;
        if (!node.left && !node.right) {
            leafs.set(depth, (leafs.get(depth) || 0) + 1);
            return;
        }
        dfs(node.left, depth + 1);
        dfs(node.right, depth + 1);
    }
    const leafs = new Map();
    dfs(root, 0);
    for (const [depth, count1] of leafs.entries()) {
        for (const [depth2, count2] of leafs.entries()) {
            if (depth2 - depth <= distance) {
                count += count1 * count2;
            }
        }
    }
    count /= 2;
    return count;
};