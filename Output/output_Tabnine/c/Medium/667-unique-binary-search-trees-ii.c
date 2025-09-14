/**https://leetcode.com/problems/unique-binary-search-trees-ii/ */
//Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
// 
//Example 1:
//Input: n = 3
//Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
//Example 2:
//Input: n = 1
//Output: [[1]]
// 
//Constraints:
//	1 <= n <= 8
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
struct TreeNode** generateTrees(int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    struct TreeNode** result = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * C(n));
    *returnSize = C(n);
    
    for (int i = 0; i < n; i++) {
        struct TreeNode** leftSubtrees = generateTrees(i);
        int leftSize = i;
        
        struct TreeNode** rightSubtrees = generateTrees(n - i - 1);
        int rightSize = n - i - 1;
        
        for (int j = 0; j < leftSize; j++) {
            for (int k = 0; k < rightSize; k++) {
                struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                root->val = i + 1;
                root->left = leftSubtrees[j];
                root->right = rightSubtrees[k];
                
                result[i * rightSize + k] = root;
            }
        }
        
        free(leftSubtrees);
        free(rightSubtrees);
    }
    
    return result;
    
}