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
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    int level = 0, maxLevel = 0;
    struct TreeNode* current = root;
    struct TreeNode* next = NULL;
    struct TreeNode** levelNodes = malloc(sizeof(struct TreeNode*) * 2000);
    int* columnSizes = malloc(sizeof(int) * 2000);
    int front = 0, rear = 0;
    
    while (current) {
        columnSizes[level] = rear - front;
        levelNodes[level] = malloc(sizeof(struct TreeNode*) * columnSizes[level]);
        
        for (int i = front; i < rear; ++i) {
            levelNodes[level][i - front] = current;
            if (current->left) {
                next = current->left;
                queuePush(&next);
            }
            if (current->right) {
                next = current->right;
                queuePush(&next);
            }
        }
        
        if (rear == 0) {
            maxLevel = level + 1;
        }
        
        current = queuePop();
        ++rear;
        
        if (current == NULL && rear == front) {
            break;
        }
        
        ++level;
    }
    
    *returnSize = maxLevel;
    *returnColumnSizes = columnSizes;
    return levelNodes;
    
}