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
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* constructFromPrePost(int* preorder, int preorderSize, int* postorder, int postorderSize) {
    // base case
    if (preorderSize == 0) return NULL;
    
    // create a new node
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    
    // find the index of the root in postorder array
    int rootIndex = 0;
    for (int i = 0; i < postorderSize; i++) {
        if (postorder[i] == preorder[0]) {
            rootIndex = i;
            break;
        }
    }
    
    // construct left subtree
    root->left = constructFromPrePost(preorder + 1, rootIndex, postorder, rootIndex);
    
    // construct right subtree
    root->right = constructFromPrePost(preorder + rootIndex + 1, preorderSize - rootIndex - 1, postorder + rootIndex, postorderSize - rootIndex - 2);
    
    return root;
    
}