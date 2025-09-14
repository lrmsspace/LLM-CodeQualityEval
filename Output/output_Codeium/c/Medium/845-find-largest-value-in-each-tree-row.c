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

    int queueSize = 1;
    struct TreeNode* queue[10000] = {root};
    int* result = (int*)malloc(sizeof(int) * 10000);
    int resultSize = 0;

    while (queueSize) {
        int maxVal = INT_MIN;
        int newQueueSize = 0;
        for (int i = 0; i < queueSize; i++) {
            struct TreeNode* curr = queue[i];
            if (curr->val > maxVal) {
                maxVal = curr->val;
            }
            if (curr->left) {
                queue[newQueueSize++] = curr->left;
            }
            if (curr->right) {
                queue[newQueueSize++] = curr->right;
            }
        }
        result[resultSize++] = maxVal;
        queueSize = newQueueSize;
    }

    *returnSize = resultSize;
    return result;
}