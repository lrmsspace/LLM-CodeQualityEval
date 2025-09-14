/**https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/ */
//Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
// 
//Example 1:
//Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//Output: [3,9,20,null,null,15,7]
//Example 2:
//Input: preorder = [-1], inorder = [-1]
//Output: [-1]
// 
//Constraints:
//	1 <= preorder.length <= 3000
//	inorder.length == preorder.length
//	-3000 <= preorder[i], inorder[i] <= 3000
//	preorder and inorder consist of unique values.
//	Each value of inorder also appears in preorder.
//	preorder is guaranteed to be the preorder traversal of the tree.
//	inorder is guaranteed to be the inorder traversal of the tree.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int rootVal = preorder[0];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = NULL;
    root->right = NULL;
    
    int rootIndex = -1;
    for (int i = 0; i < inorderSize; i++) {
        if (inorder[i] == rootVal) {
            rootIndex = i;
            break;
        }
    }
    
    if (rootIndex != -1) {
        int leftSize = rootIndex;
        int rightSize = inorderSize - rootIndex - 1;
        
        if (leftSize > 0) {
            int* leftPreorder = (int*)malloc(leftSize * sizeof(int));
            int* leftInorder = (int*)malloc(leftSize * sizeof(int));
            for (int i = 0; i < leftSize; i++) {
                leftPreorder[i] = preorder[i+1];
                leftInorder[i] = inorder[i];
            }
            root->left = buildTree(leftPreorder, leftSize, leftInorder, leftSize);
            free(leftPreorder);
            free(leftInorder);
        }
        
        if (rightSize > 0) {
            int* rightPreorder = (int*)malloc(rightSize * sizeof(int));
            int* rightInorder = (int*)malloc(rightSize * sizeof(int));
            for (int i = 0; i < rightSize; i++) {
                rightPreorder[i] = preorder[leftSize + 1 + i];
                rightInorder[i] = inorder[rootIndex + 1 + i];
            }
            root->right = buildTree(rightPreorder, rightSize, rightInorder, rightSize);
            free(rightPreorder);
            free(rightInorder);
        }
    }
    
    return root;
}
