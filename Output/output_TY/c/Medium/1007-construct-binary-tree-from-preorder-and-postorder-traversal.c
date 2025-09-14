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
struct TreeNode* constructFromPrePost(int* preorder, int preorderSize, int* postorder, int postorderSize){
    if (preorderSize == 0) return NULL;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    if (preorderSize == 1) return root;
    int i;
    for (i = 0; i < postorderSize; i++) {
        if (postorder[i] == preorder[1]) break;
    }
    root->left = constructFromPrePost(preorder + 1, i + 1, postorder, i);
    root->right = constructFromPrePost(preorder + i + 2, preorderSize - i - 2, postorder + i, postorderSize - i - 1);
    return root;
}