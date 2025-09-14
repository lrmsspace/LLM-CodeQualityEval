/**https://leetcode.com/problems/binary-tree-level-order-traversal/ */
//Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
// 
//Example 1:
//Input: root = [3,9,20,null,null,15,7]
//Output: [[3],[9,20],[15,7]]
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
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    int** res = (int**)malloc(sizeof(int*) * 1000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);
    int front = 0, rear = 0;
    struct TreeNode* queue[1000];
    queue[rear++] = root;
    while (front < rear) {
        int size = rear - front;
        res[*returnSize] = (int*)malloc(sizeof(int) * size);
        (*returnColumnSizes)[*returnSize] = size;
        for (int i = 0; i < size; ++i) {
            struct TreeNode* node = queue[front++];
            res[*returnSize][i] = node->val;
            if (node->left) {
                queue[rear++] = node->left;
            }
            if (node->right) {
                queue[rear++] = node->right;
            }
        }
        (*returnSize)++;
    }
    return res;    
}