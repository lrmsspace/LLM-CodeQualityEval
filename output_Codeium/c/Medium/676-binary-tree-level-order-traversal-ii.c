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
    
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = (int*)malloc(0 * sizeof(int));
        return (int**)malloc(0 * sizeof(int*));
    }
    int* columnSizes = (int*)malloc(2000 * sizeof(int));
    int size = 0;
    struct TreeNode** queue = (struct TreeNode**)malloc(2000 * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (rear > front) {
        struct TreeNode* node = queue[front++];
        columnSizes[size]++;
        if (node->left) {
            queue[rear++] = node->left;
        }
        if (node->right) {
            queue[rear++] = node->right;
        }
    }
    *returnSize = size;
    *returnColumnSizes = columnSizes;
    int** res = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        res[i] = (int*)malloc(columnSizes[i] * sizeof(int));
    }
    for (int i = size - 1; i >= 0; i--) {
        struct TreeNode* node = queue[rear - 1 - i];
        res[i][columnSizes[i] - 1] = node->val;
    }
    free(queue);
    return res;
}
