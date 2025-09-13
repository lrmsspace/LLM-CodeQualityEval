/**https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/ */
//Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
//You can return the answer in any order.
// 
//Example 1:
//Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
//Output: [7,4,1]
//Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
//Example 2:
//Input: root = [1], target = 1, k = 3
//Output: []
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 500].
//	0 <= Node.val <= 500
//	All the values Node.val are unique.
//	target is the value of one of the nodes in the tree.
//	0 <= k <= 1000
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

void dfs(struct TreeNode *node, struct TreeNode *target, int k, int *ans, int *size) {
    if (node == NULL) return;
    if (node == target) {
        queueAdd(node, k, ans, size);
        return;
    }
    dfs(node->left, target, k, ans, size);
    dfs(node->right, target, k, ans, size);
    if (node->left == target || node->right == target) {
        queueAdd(node, k - 1, ans, size);
    }
}

void queueAdd(struct TreeNode *node, int k, int *ans, int *size) {
    if (k == 0) {
        ans[(*size)++] = node->val;
        return;
    }
    if (node->left != NULL) queueAdd(node->left, k - 1, ans, size);
    if (node->right != NULL) queueAdd(node->right, k - 1, ans, size);
}

int* distanceK(struct TreeNode* root, struct TreeNode* target, int k, int* returnSize) {
    
    int *ans = (int *)malloc(sizeof(int) * (k + 1));
    int size = 0;
    dfs(root, target, k, ans, &size);
    *returnSize = size;
    return ans; 
}