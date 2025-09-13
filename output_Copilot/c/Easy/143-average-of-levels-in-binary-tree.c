/**https://leetcode.com/problems/average-of-levels-in-binary-tree/ */
//Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.
// 
//Example 1:
//Input: root = [3,9,20,null,null,15,7]
//Output: [3.00000,14.50000,11.00000]
//Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
//Hence return [3, 14.5, 11].
//Example 2:
//Input: root = [3,9,20,15,7]
//Output: [3.00000,14.50000,11.00000]
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
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
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    double *res = (double *)malloc(sizeof(double) * 1000);
    int *count = (int *)malloc(sizeof(int) * 1000);
    memset(res, 0, sizeof(double) * 1000);
    memset(count, 0, sizeof(int) * 1000);
    *returnSize = 0;
    struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 1000);
    int front = 0, rear = 0;
    queue[rear++] = root;
    count[0] = 1;
    while (front < rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            struct TreeNode *node = queue[front++];
            res[*returnSize] += node->val;
            if (node->left) {
                queue[rear++] = node->left;
            }
            if (node->right) {
                queue[rear++] = node->right;
            }
        }
        res[*returnSize] /= count[*returnSize];
        (*returnSize)++;
        count[*returnSize] = rear - front;
    }
    return res;    
}