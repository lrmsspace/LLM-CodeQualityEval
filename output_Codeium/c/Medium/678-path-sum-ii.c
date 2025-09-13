/**https://leetcode.com/problems/path-sum-ii/ */
//Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
//A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
// 
//Example 1:
//Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
//Output: [[5,4,11,2],[5,8,4,5]]
//Explanation: There are two paths whose sum equals targetSum:
//5 + 4 + 11 + 2 = 22
//5 + 8 + 4 + 5 = 22
//Example 2:
//Input: root = [1,2,3], targetSum = 5
//Output: []
//Example 3:
//Input: root = [1,2], targetSum = 0
//Output: []
// 
//Constraints:
//	The number of nodes in the tree is in the range [0, 5000].
//	-1000 <= Node.val <= 1000
//	-1000 <= targetSum <= 1000
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void dfs(struct TreeNode* root, int targetSum, int* path, int* pathSize, int** result, int* resultSize, int* resultColumnSizes) {
    if (!root) {
        return;
    }
    
    path[(*pathSize)++] = root->val;
    if (!root->left && !root->right) {
        int sum = 0;
        for (int i = 0; i < *pathSize; i++) {
            sum += path[i];
        }
        if (sum == targetSum) {
            result[(*resultSize)++] = (int*)malloc((*pathSize + 1) * sizeof(int));
            resultColumnSizes[(*resultSize) - 1] = *pathSize;
            for (int i = 0; i < *pathSize; i++) {
                result[(*resultSize) - 1][i] = path[i];
            }
        }
    }
    
    dfs(root->left, targetSum, path, pathSize, result, resultSize, resultColumnSizes);
    dfs(root->right, targetSum, path, pathSize, result, resultSize, resultColumnSizes);
    
    (*pathSize)--;
}
int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {
    
    *returnSize = 0;
    *returnColumnSizes = NULL;
    if (!root) {
        return NULL;
    }
    
    int* path = (int*)malloc(501 * sizeof(int));
    int pathSize = 0;
    
    int** result = (int**)malloc(501 * sizeof(int*));
    int resultSize = 0;
    int* resultColumnSizes = (int*)malloc(501 * sizeof(int));
    
    dfs(root, targetSum, path, &pathSize, result, &resultSize, resultColumnSizes);
    *returnSize = resultSize;
    *returnColumnSizes = resultColumnSizes;
    return result;
}
    