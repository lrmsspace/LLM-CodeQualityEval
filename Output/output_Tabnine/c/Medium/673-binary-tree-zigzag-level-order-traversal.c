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
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    int** result = (int**)malloc(sizeof(int*) * 1000);
    int* columnSizes = (int*)malloc(sizeof(int) * 1000);
    int row = 0, col = 0;
    int direction = 0;
    int count = 1;
    
    struct TreeNode* queue[2000];
    queue[0] = root;
    
    while (count > 0) {
        result[row] = (int*)malloc(sizeof(int) * count);
        columnSizes[row] = count;
        
        int front = 0, rear = 0;
        while (front < rear) {
            struct TreeNode* node = queue[front++];
            result[row][col++] = node->val;
            
            if (node->left) {
                queue[rear++] = node->left;
            }
            if (node->right) {
                queue[rear++] = node->right;
            }
        }
        
        if (direction == 0) {
            direction = 1;
        } else {
            direction = 0;
            col = 0;
            row++;
        }
        
        count = rear;
    }
    
    *returnSize = row;
    *returnColumnSizes = columnSizes;
    return result;
    
}