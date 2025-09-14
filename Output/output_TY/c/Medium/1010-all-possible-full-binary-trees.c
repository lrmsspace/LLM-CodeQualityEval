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
struct TreeNode** allPossibleFBT(int n, int* returnSize){
    *returnSize = 0;
    if (n == 1) {
        struct TreeNode** ret = malloc(sizeof(struct TreeNode*));
        ret[0] = malloc(sizeof(struct TreeNode));
        ret[0]->val = 0;
        ret[0]->left = NULL;
        ret[0]->right = NULL;
        *returnSize = 1;
        return ret;
    }
    struct TreeNode** ret = malloc(sizeof(structTreeNode*) * (n - 1));
    for (int i = 1; i < n; i += 2) {
        struct TreeNode** left = allPossibleFBT(i);
        struct TreeNode** right = allPossibleFBT(n - i - 1);
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < n - i - 1; k++) {
                struct TreeNode* node= malloc(sizeof(struct TreeNode));
            }
        }
    }
    return ret;
}