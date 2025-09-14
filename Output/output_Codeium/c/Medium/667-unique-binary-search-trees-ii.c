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
struct TreeNode** generateTreesUtil(int start, int end, int* size) {
    if (start > end) {
        *size = 1;
        struct TreeNode** baseResult = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        baseResult[0] = NULL;
        return baseResult;
    }
    
    int totalSize = 0;
    struct TreeNode** allTrees = NULL;
    
    for (int i = start; i <= end; i++) {
        int leftSize = 0, rightSize = 0;
        struct TreeNode** leftTrees = generateTreesUtil(start, i - 1, &leftSize);
        struct TreeNode** rightTrees = generateTreesUtil(i + 1, end, &rightSize);
        
        for (int l = 0; l < leftSize; l++) {
            for (int r = 0; r < rightSize; r++) {
                struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                root->val = i;
                root->left = leftTrees[l];
                root->right = rightTrees[r];

                allTrees = (struct TreeNode**)realloc(allTrees, sizeof(struct TreeNode*) * (totalSize + 1));
                allTrees[totalSize++] = root;
            }
        }
        free(leftTrees);
        free(rightTrees);
    }
    
    *size = totalSize;
    return allTrees;
}

struct TreeNode** generateTrees(int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    return generateTreesUtil(1, n, returnSize);
}
