/**https://leetcode.com/problems/binary-tree-level-order-traversal-ii/ */
//Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).
// 
//Example 1:
//Input: root = [3,9,20,null,null,15,7]
//Output: [[15,7],[9,20],[3]]
//Example 2:
//Input: root = [1]
//Output: [[1]]
//Example 3:
//Input: root = []
//Output: []
// 
//Constraints:
//	The number of nodes in the tree is in the range [0, 2000].
//	-1000 <= Node.val <= 1000
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
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int** result = (int**)malloc(sizeof(int*) * 2000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);
    int** queue = (int**)malloc(sizeof(int*) * 2000);
    int front = 0, rear = 0;
    queue[rear++] = root;
    int levelSize = 1;
    while (front < rear) {
        int* level = (int*)malloc(sizeof(int) * levelSize);
        int levelIndex = 0;
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            level[levelIndex++] = node->val;
            if (node->left != NULL) {
                queue[rear++] = node->left;
            }
            if (node->right != NULL) {
                queue[rear++] = node->right;
            }
        }
        result[--(*returnSize)] = level;
        (*returnColumnSizes)[*returnSize] = levelSize;
        levelSize = rear - front;
    }
    return result;
}