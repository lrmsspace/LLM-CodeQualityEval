/**https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/ */
//Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.
//If there exist multiple answers, you can return any of them.
// 
//Example 1:
//Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
//Output: [1,2,3,4,5,6,7]
//Example 2:
//Input: preorder = [1], postorder = [1]
//Output: [1]
// 
//Constraints:
//	1 <= preorder.length <= 30
//	1 <= preorder[i] <= preorder.length
//	All the values of preorder are unique.
//	postorder.length == preorder.length
//	1 <= postorder[i] <= postorder.length
//	All the values of postorder are unique.
//	It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
var constructFromPrePost = function(preorder, postorder) {
    const map = new Map();
    postorder.forEach((val, index) => {
        map.set(val, index);
    });
    
    function build(preStart, preEnd, postStart, postEnd) {
        if (preStart > preEnd || postStart > postEnd) return null;
        const rootVal = preorder[preStart];
        const root = new TreeNode(rootVal);
        
        if (preStart === preEnd) return root;
        
        const leftRootVal = preorder[preStart + 1];
        const leftRootIndex = map.get(leftRootVal);
        const leftSubtreeSize = leftRootIndex - postStart + 1;
        
        root.left = build(preStart + 1, preStart + leftSubtreeSize, postStart, leftRootIndex);
        root.right = build(preStart + leftSubtreeSize + 1, preEnd, leftRootIndex + 1, postEnd - 1);
        
        return root;
    }
    
    return build(0, preorder.length - 1, 0, postorder.length - 1);    
};