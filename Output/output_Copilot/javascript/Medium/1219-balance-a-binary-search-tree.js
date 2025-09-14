/**https://leetcode.com/problems/balance-a-binary-search-tree/ */
//Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
//A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
// 
//Example 1:
//Input: root = [1,null,2,null,3,null,4,null,null]
//Output: [2,1,3,null,null,null,4]
//Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
//Example 2:
//Input: root = [2,1,3]
//Output: [2,1,3]
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
//	1 <= Node.val <= 105
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
 * @return {TreeNode}
 */
var balanceBST = function(root) {
    let arr = [];
    const inorder = (node) => {
        if (!node) return;
        inorder(node.left);
        arr.push(node.val);
        inorder(node.right);
    };
    inorder(root);

    const buildTree = (start, end) => {
        if (start > end) return null;
        const mid = Math.floor((start + end) / 2);
        const node = new TreeNode(arr[mid]);
        node.left = buildTree(start, mid - 1);
        node.right = buildTree(mid + 1, end);
        return node;
    };

    return buildTree(0, arr.length - 1);    
};