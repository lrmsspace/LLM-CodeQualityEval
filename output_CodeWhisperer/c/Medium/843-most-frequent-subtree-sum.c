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
    int* result = (int*)malloc(sizeof(int) * 10000);
    int resultSize = 0;
    int* sum = (int*)malloc(sizeof(int) * 10000);
    int sumSize = 0;
    int* count = (int*)malloc(sizeof(int) * 10000);
    int countSize = 0;
    int* maxCount = (int*)malloc(sizeof(int));
    *maxCount = 0;
    int* findFrequentTreeSumHelper(struct TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = findFrequentTreeSumHelper(root->left);
        int right = findFrequentTreeSumHelper(root->right);
        int currentSum = root->val + left + right;
        int i;
        for (i = 0; i < sumSize; i++) {
            if (sum[i] == currentSum) {
                count[i]++;
                if (count[i] > *maxCount) {
                    *maxCount = count[i];
                }
                return currentSum;
            }
        }
        sum[sumSize] = currentSum;
        count[sumSize] = 1;
        sumSize++;
        if (*maxCount == 1) {
            result[resultSize] = currentSum;
            resultSize++;
        }
        return currentSum;
    }
    findFrequentTreeSumHelper(root);
    *returnSize = resultSize;
    return result;
}