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
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    int max_level = 0;
    int current_level = 0;
    int size = 0;
    int capacity = 1;
    struct TreeNode** queue = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    queue[0] = root;
    (*returnSize)++;
    (*returnColumnSizes) = (int*)malloc(sizeof(int));
    (*returnColumnSizes)[0] = 1;
    
    while (size > 0) {
        size--;
        current_level++;
        
        if (current_level > max_level) {
            max_level = current_level;
            capacity *= 2;
            queue = (struct TreeNode**)realloc(queue, capacity * sizeof(struct TreeNode*));
            (*returnColumnSizes) = (int*)realloc((*returnColumnSizes), max_level * sizeof(int));
            (*returnColumnSizes)[max_level - 1] = 0;
        }
        
        struct TreeNode* node = queue[size];
        (*returnColumnSizes)[max_level - 1]++;
        
        if (node->left) {
            queue[size] = node->left;
            size++;
        }
        
        if (node->right) {
            queue[size] = node->right;
            size++;
        }
    }
    
    int** result = (int**)malloc(max_level * sizeof(int*));
    for (int i = 0; i < max_level; i++) {
        result[i] = (int*)malloc((*returnColumnSizes)[i] * sizeof(int));
        for (int j = 0; j < (*returnColumnSizes)[i]; j++) {
            result[i][j] = queue[i * (*returnColumnSizes)[i] + j]->val;
        }
    }
    
    free(queue);
    
    return result;
    
}