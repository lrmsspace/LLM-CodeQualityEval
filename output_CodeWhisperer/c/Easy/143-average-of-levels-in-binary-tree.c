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
    double* result = (double*)malloc(sizeof(double) * 10000);
    int* count = (int*)malloc(sizeof(int) * 10000);
    int i = 0, j = 0, k = 0;
    struct TreeNode* queue[10000];
    queue[0] = root;
    count[0] = 1;
    while (i <= j) {
        k = 0;
        double sum = 0;
        for (int l = 0; l < count[i]; l++) {
            sum += queue[i]->val;
            if (queue[i]->left) {
                k++;
                queue[++j] = queue[i]->left;
            }
            if (queue[i]->right) {
                k++;
                queue[++j] = queue[i]->right;
            }
            i++;
        }
        result[i - 1] = sum / count[i];
        count[i] = k;
    }
    *returnSize = i;
    return result;
    
}