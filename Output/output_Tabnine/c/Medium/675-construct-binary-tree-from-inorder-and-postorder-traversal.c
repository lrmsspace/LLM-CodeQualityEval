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
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (inorderSize == 0) return NULL;
    
    int rootVal = postorder[postorderSize - 1];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = root->right = NULL;
    
    int rootIndex = -1;
    for (int i = 0; i < inorderSize; i++) {
        if (inorder[i] == rootVal) {
            rootIndex = i;
            break;
        }
    }
    
    if (rootIndex > 0) {
        root->left = buildTree(inorder, rootIndex, postorder, rootIndex);
    }
    
    if (rootIndex < inorderSize - 1) {
        root->right = buildTree(inorder + rootIndex + 1, inorderSize - rootIndex - 1, postorder + rootIndex, inorderSize - rootIndex - 1);
    }
    
    return root;
    
}