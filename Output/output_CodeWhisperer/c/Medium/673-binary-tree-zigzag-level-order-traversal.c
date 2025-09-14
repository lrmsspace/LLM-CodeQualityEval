/**https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/ */
//Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
// 
//Example 1:
//Input: root = [3,9,20,null,null,15,7]
//Output: [[3],[20,9],[15,7]]
//Example 2:
//Input: root = [1]
//Output: [[1]]
//Example 3:
//Input: root = []
//Output: []
// 
//Constraints:
//	The number of nodes in the tree is in the range [0, 2000].
//	-100 <= Node.val <= 100
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
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * 2000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);
    *returnSize = 0;
    if (root == NULL) {
        return result;
    }
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 2000);
    int front = 0, rear = 0;
    queue[rear++] = root;
    int level = 0;
    while (front < rear) {
        int size = rear - front;
        result[*returnSize] = (int*)malloc(sizeof(int) * size);
        (*returnColumnSizes)[*returnSize] = size;
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            if (level % 2 == 0) {
                result[*returnSize][i] = node->val;
            } else {
                result[*returnSize][size - i - 1] = node->val;
            }
            if (node->left != NULL) {
                queue[rear++] = node->left;
            }
            if (node->right != NULL) {
                queue[rear++] = node->right;
            }
        }
        (*returnSize)++;
        level++;
    }
    return result;
}