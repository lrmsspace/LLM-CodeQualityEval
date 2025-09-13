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
    struct TreeNode** res = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
    *returnSize = 0;
    if (n == 1) {
        struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->val = 0;
        root->left = NULL;
        root->right = NULL;
        res[(*returnSize)++] = root;
        return res;
    }
    for (int i = 1; i < n; i += 2) {
        int leftSize, rightSize;
        struct TreeNode** left = allPossibleFBT(i, &leftSize);
        struct TreeNode** right = allPossibleFBT(n - i - 1, &rightSize);
        for (int j = 0; j < leftSize; j++) {
            for (int k = 0; k < rightSize; k++) {
                struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                root->val = 0;
                root->left = left[j];
                root->right = right[k];
                res[(*returnSize)++] = root;
            }
        }
    }
    return res;    
}