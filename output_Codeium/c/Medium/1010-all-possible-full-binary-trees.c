/**https://leetcode.com/problems/all-possible-full-binary-trees/ */
//Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.
//Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.
//A full binary tree is a binary tree where each node has exactly 0 or 2 children.
// 
//Example 1:
//Input: n = 7
//Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
//Example 2:
//Input: n = 3
//Output: [[0,0,0]]
// 
//Constraints:
//	1 <= n <= 20
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** allPossibleFBT(int n, int* returnSize) {
    if (n % 2 == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    if (n == 1) {
        struct TreeNode** result = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        result[0] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        result[0]->val = 0;
        result[0]->left = NULL;
        result[0]->right = NULL;
        *returnSize = 1;
        return result;
    }
    
    int i;
    struct TreeNode** leftTrees = allPossibleFBT(n - 1, returnSize);
    struct TreeNode** rightTrees = allPossibleFBT(n - 1, returnSize);
    struct TreeNode** result = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * (*returnSize) * (*returnSize));
    *returnSize = 0;
    for (i = 0; i < *returnSize; i++) {
        struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->val = 0;
        root->left = leftTrees[i];
        root->right = rightTrees[i];
        result[*returnSize++] = root;
    }
    for (i = 0; i < *returnSize; i++) {
        struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->val = 0;
        root->left = leftTrees[i];
        root->right = rightTrees[*returnSize - 1 - i];
        result[*returnSize++] = root;
    }
    free(leftTrees);
    free(rightTrees);
    return result;  
}