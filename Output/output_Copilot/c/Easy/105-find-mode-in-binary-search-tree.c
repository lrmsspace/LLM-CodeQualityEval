/**https://leetcode.com/problems/find-mode-in-binary-search-tree/ */
//Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.
//If the tree has more than one mode, return them in any order.
//Assume a BST is defined as follows:
//	The left subtree of a node contains only nodes with keys less than or equal to the node's key.
//	The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
//	Both the left and right subtrees must also be binary search trees.
// 
//Example 1:
//Input: root = [1,null,2,2]
//Output: [2]
//Example 2:
//Input: root = [0]
//Output: [0]
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
//	-105 <= Node.val <= 105
// 
//Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
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
int* findMode(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int maxCount = 0;
    int count = 0;
    int pre = 0;
    int* result = (int*)malloc(sizeof(int) * 10000);
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10000);
    int top = -1;
    struct TreeNode* cur = root;
    while (top != -1 || cur != NULL) {
        while (cur != NULL) {
            stack[++top] = cur;
            cur = cur->left;
        }
        cur = stack[top--];
        if (pre == cur->val) {
            count++;
        } else {
            count = 1;
            pre = cur->val;
        }
        if (count == maxCount) {
            result[(*returnSize)++] = cur->val;
        } else if (count > maxCount) {
            maxCount = count;
            *returnSize = 1;
            result[0] = cur->val;
        }
        cur = cur->right;
    }
    return result;    
}