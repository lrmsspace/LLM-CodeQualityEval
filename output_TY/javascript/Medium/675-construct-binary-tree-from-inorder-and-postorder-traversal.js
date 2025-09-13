/**https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/ */
//Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
// 
//Example 1:
//Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
//Output: [3,9,20,null,null,15,7]
//Example 2:
//Input: inorder = [-1], postorder = [-1]
//Output: [-1]
// 
//Constraints:
//	1 <= inorder.length <= 3000
//	postorder.length == inorder.length
//	-3000 <= inorder[i], postorder[i] <= 3000
//	inorder and postorder consist of unique values.
//	Each value of postorder also appears in inorder.
//	inorder is guaranteed to be the inorder traversal of the tree.
//	postorder is guaranteed to be the postorder traversal of the tree.
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} inorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
var buildTree = function(inorder, postorder) {
    let root = new TreeNode(postorder[postorder.length - 1]);
    let rootIndex = inorder.indexOf(postorder[postorder.length - 1]);
    
    let leftInorder = inorder.slice(0, rootIndex);
    let rightInorder = inorder.slice(rootIndex + 1);
    
    let leftPostorder = postorder.slice(0, leftInorder.length);
    let rightPostorder = postorder.slice(leftInorder.length, postorder.length - 1);
    
    if(leftInorder.length > 0) root.left = buildTree(leftInorder, leftPostorder);
    if(rightInorder.length > 0) root.right = buildTree(rightIn), rightPostorder);
    return root;
};