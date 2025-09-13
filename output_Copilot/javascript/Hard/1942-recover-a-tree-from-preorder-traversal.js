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
    let stack = [];
    let i = 0;
    while (i < traversal.length) {
        let level = 0;
        while (traversal[i] === '-') {
            level++;
            i++;
        }
        let val = '';
        while (i < traversal.length && traversal[i] !== '-') {
            val += traversal[i];
            i++;
        }
        val = parseInt(val);
        let node = new TreeNode(val);
        if (level === stack.length) {
            if (stack.length > 0) {
                stack[stack.length - 1].left = node;
            }
        } else {
            while (stack.length > level) {
                stack.pop();
            }
            stack[stack.length - 1].right = node;
        }
        stack.push(node);
    }
    return stack[0];    
};