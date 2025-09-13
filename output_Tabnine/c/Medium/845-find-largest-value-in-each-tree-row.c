/**https://leetcode.com/problems/find-largest-value-in-each-tree-row/ */
//Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
// 
//Example 1:
//Input: root = [1,3,2,5,3,null,9]
//Output: [1,3,9]
//Example 2:
//Input: root = [1,2,3]
//Output: [1,3]
// 
//Constraints:
//	The number of nodes in the tree will be in the range [0, 104].
//	-231 <= Node.val <= 231 - 1
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
int* largestValues(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    
    int maxRows = 0;
    struct TreeNode* current = root;
    while (current) {
        maxRows++;
        current = current->left? current->left : current->right;
    }
    
    int* result = malloc(maxRows * sizeof(int));
    int* start = result;
    int* end = result + maxRows;
    
    while (root) {
        *start = root->val;
        start++;
        
        if (root->left) {
            root = root->left;
        } else if (root->right) {
            root = root->right;
        } else {
            root = root->right? root->right : root->left;
        }
    }
    
    *returnSize = maxRows;
    return result;
    
}