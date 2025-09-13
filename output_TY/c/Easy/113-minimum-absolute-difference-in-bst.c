/**https://leetcode.com/problems/minimum-absolute-difference-in-bst/ */
//Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
// 
//Example 1:
//Input: root = [4,2,6,1,3]
//Output: 1
//Example 2:
//Input: root = [1,0,48,null,null,12,49]
//Output: 1
// 
//Constraints:
//	The number of nodes in the tree is in the range [2, 104].
//	0 <= Node.val <= 105
// 
//Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getMinimumDifference(struct TreeNode* root){
    int prev = INT_MIN; // 初始化前一个节点值为最小整数
    int minDiff = INT_MAX; // 初始化最小绝对差为最大整数
    while (root) {
        if (!root->left) { // 如果当前节点没有左子树
            if (prev != INT_MIN) { // 如果前一个节点不为最小整数
                minDiff = fmin(minDiff, root->val - prev); // 更新最小绝对差
            }
            prev = root->val; // 更新前一个节点为当前节点
            root = root->right; // 移动到右子树
        }
    }
    return minDiff;
}