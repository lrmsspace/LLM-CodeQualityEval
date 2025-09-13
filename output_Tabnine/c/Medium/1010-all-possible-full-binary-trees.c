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
    struct TreeNode** dp = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * (n + 1));
    dp[0] = dp[1] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    dp[0]->val = dp[1]->val = 0;
    dp[0]->left = dp[0]->right = dp[1]->left = dp[1]->right = NULL;
    *returnSize = 1;
    for (int i = 3; i <= n; i += 2) {
        *returnSize = i;
        dp[i] = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * i);
        for (int j = 0; j < i; j++) {
            int leftSize = j, rightSize = i - 1 - j;
            for (int left = 0; left < leftSize; left++) {
                for (int right = 0; right < rightSize; right++) {
                    dp[i][j] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                    dp[i][j]->val = 0;
                    dp[i][j]->left = dp[leftSize][left];
                    dp[i][j]->right = dp[rightSize][right];
                }
            }
        }
    }
    return dp;    
}