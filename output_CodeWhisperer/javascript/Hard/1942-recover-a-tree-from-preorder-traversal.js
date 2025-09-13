/**https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/ */
//We run a preorder depth-first search (DFS) on the root of a binary tree.
//At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.
//If a node has only one child, that child is guaranteed to be the left child.
//Given the output traversal of this traversal, recover the tree and return its root.
// 
//Example 1:
//Input: traversal = "1-2--3--4-5--6--7"
//Output: [1,2,5,3,4,6,7]
//Example 2:
//Input: traversal = "1-2--3---4-5--6---7"
//Output: [1,2,5,3,null,6,null,4,null,7]
//Example 3:
//Input: traversal = "1-401--349---90--88"
//Output: [1,401,null,349,88,90]
// 
//Constraints:
//	The number of nodes in the original tree is in the range [1, 1000].
//	1 <= Node.val <= 109
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {string} traversal
 * @return {TreeNode}
 */
var recoverFromPreorder = function(traversal) {
    let i = 0;
    const dfs = (depth) => {
        let num = 0;
        while (i + num < traversal.length && traversal[i + num] !== '-') {
            num++;
        }
        const val = parseInt(traversal.substring(i, i + num));
        i += num;
        const node = new TreeNode(val);
        if (depth === 0) return node;
        let j = i;
        while (j < traversal.length && traversal[j] === '-') {
            j++;
        }
        const diff = j - i;
        if (diff === depth) {
            node.left = dfs(depth + 1);
        }
        if (diff > depth) {
            node.right = dfs(depth + 1);
        }
        return node;
    }
    return dfs(0);
};