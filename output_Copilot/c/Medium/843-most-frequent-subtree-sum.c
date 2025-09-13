/**https://leetcode.com/problems/most-frequent-subtree-sum/ */
//Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order.
//The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).
// 
//Example 1:
//Input: root = [5,2,-3]
//Output: [2,-3,4]
//Example 2:
//Input: root = [5,2,-5]
//Output: [2]
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
//	-105 <= Node.val <= 105
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
int* findFrequentTreeSum(struct TreeNode* root, int* returnSize) {
    int *res = (int *)malloc(sizeof(int) * 10000);
    int *sum = (int *)malloc(sizeof(int) * 10000);
    int max = 0;
    int count = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int *ret = (int *)malloc(sizeof(int) * 10000);
    *returnSize = 0;
    if (!root) {
        return NULL;
    }
    for (i = 0; i < 10000; i++) {
        res[i] = 0;
        sum[i] = 0;
    }
    dfs(root, sum, res, &max, &count);
    for (i = 0; i < 10000; i++) {
        if (res[i] == max) {
            ret[k++] = i;
        }
    }
    *returnSize = k;
    return ret;    
}