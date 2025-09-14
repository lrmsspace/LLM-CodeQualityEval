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
    int* result = malloc(sizeof(int) * 1000);
    int* count = malloc(sizeof(int) * 2001);
    memset(count, 0, sizeof(int) * 2001);
    int maxCount = 0;
    
    findSubtreeSum(root, count, &maxCount);
    
    int i = 0;
    for (int j = 0; j < 2001; j++) {
        if (count[j] == maxCount) {
            result[i++] = j;
        }
    }
    
    *returnSize = i;
    return result;
    
}