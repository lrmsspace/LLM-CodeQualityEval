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
    if (preorderSize == 0) {
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    if (preorderSize == 1) {
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    int leftRoot = preorder[1];
    int leftSize = 0;
    for (int i = 0; i < postorderSize; i++) {
        if (postorder[i] == leftRoot) {
            leftSize = i + 1;
            break;
        }
    }
    root->left = constructFromPrePost(preorder + 1, leftSize, postorder, leftSize);
    root->right = constructFromPrePost(preorder + leftSize + 1, preorderSize - leftSize - 1, postorder + leftSize, postorderSize - leftSize - 1);
    return root;
}