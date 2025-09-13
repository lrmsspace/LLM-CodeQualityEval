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
int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    int **res = (int**)malloc(sizeof(int*) * 1000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);
    int *path = (int*)malloc(sizeof(int) * 1000);
    int pathLen = 0;
    int sum = 0;
    struct TreeNode **stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
    int top = 0;
    struct TreeNode *pre = NULL;
    struct TreeNode *cur = root;
    while (cur || top > 0) {
        while (cur) {
            stack[top++] = cur;
            sum += cur->val;
            path[pathLen++] = cur->val;
            cur = cur->left;
        }
        cur = stack[top - 1];
        if (!cur->left && !cur->right && sum == targetSum) {
            res[*returnSize] = (int*)malloc(sizeof(int) * pathLen);
            memcpy(res[*returnSize], path, sizeof(int) * pathLen);
            (*returnColumnSizes)[*returnSize] = pathLen;
            (*returnSize)++;
        }
        if (cur->right && cur->right != pre) {
            cur = cur->right;
        } else {
            pre = cur;
            top--;
            sum -= cur->val;
            pathLen--;
            cur = NULL;
        }
    }
    free(stack);
    free(path);
    return res;    
}