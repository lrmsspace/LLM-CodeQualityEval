/**https://leetcode.com/problems/binary-tree-postorder-traversal/ */
//Given the root of a binary tree, return the postorder traversal of its nodes' values.
// 
//Example 1:
//Input: root = [1,null,2,3]
//Output: [3,2,1]
//Explanation:
//Example 2:
//Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
//Output: [4,6,7,5,2,9,8,3,1]
//Explanation:
//Example 3:
//Input: root = []
//Output: []
//Example 4:
//Input: root = [1]
//Output: [1]
// 
//Constraints:
//	The number of the nodes in the tree is in the range [0, 100].
//	-100 <= Node.val <= 100
// 
//Follow up: Recursive solution is trivial, could you do it iteratively?
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
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }
    int* res = (int*)malloc(sizeof(int) * 100);
    struct TreeNode* stack[100];
    int top = -1;
    struct TreeNode* cur = root;
    struct TreeNode* pre = NULL;
    while (cur || top != -1) {
        while (cur) {
            stack[++top] = cur;
            cur = cur->left;
        }
        cur = stack[top];
        if (cur->right == NULL || cur->right == pre) {
            res[(*returnSize)++] = cur->val;
            pre = cur;
            top--;
            cur = NULL;
        } else {
            cur = cur->right;
        }
    }
    return res;    
}