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
    struct TreeNode** result = malloc(sizeof(struct TreeNode*) * 1000);
    *returnSize = 0;
    if (n % 2 == 0) {
        return result;
    }
    if (n == 1) {
        struct TreeNode* node = malloc(sizeof(struct TreeNode));
        node->val = 0;
        node->left = NULL;
        node->right = NULL;
        result[*returnSize] = node;
        (*returnSize)++;
        return result;
    }
    for (int i = 1; i < n; i += 2) {
        struct TreeNode** left = allPossibleFBT(i, returnSize);
        struct TreeNode** right = allPossibleFBT(n - i - 1, returnSize);
        for (int j = 0; j < *returnSize; j++) {
            for (int k = 0; k < *returnSize; k++) {
                struct TreeNode* node = malloc(sizeof(struct TreeNode));
                node->val = 0;
                node->left = left[j];
                node->right = right[k];
                result[*returnSize] = node;
                (*returnSize)++;
            }
        }
    }
    return result;
}