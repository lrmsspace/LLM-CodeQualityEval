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
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10000);
    int* res = (int*)malloc(sizeof(int) * 10000);
    int head = 0, tail = 0, level = 0;
    queue[tail++] = root;
    while (head < tail) {
        int max = INT_MIN;
        int size = tail - head;
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[head++];
            if (node->val > max) {
                max = node->val;
            }
            if (node->left) {
                queue[tail++] = node->left;
            }
            if (node->right) {
                queue[tail++] = node->right;
            }
        }
        res[level++] = max;
    }
    *returnSize = level;
    return res;    
}