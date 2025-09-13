/**https://leetcode.com/problems/binary-tree-inorder-traversal/ */
//Given the root of a binary tree, return the inorder traversal of its nodes' values.
// 
//Example 1:
//Input: root = [1,null,2,3]
//Output: [1,3,2]
//Explanation:
//Example 2:
//Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
//Output: [4,2,6,5,7,1,3,9,8]
//Explanation:
//Example 3:
//Input: root = []
//Output: []
//Example 4:
//Input: root = [1]
//Output: [1]
// 
//Constraints:
//	The number of nodes in the tree is in the range [0, 100].
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
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *res = (int *)malloc(101 * sizeof(int));
    int index = 0;
    struct TreeNode *stack[101];
    int top = 0;
    while (root != NULL || top > 0) {
        while (root != NULL) {
            stack[top++] = root;
            root = root->left;
        }
        root = stack[--top];
        res[index++] = root->val;
        root = root->right;
    }
    *returnSize = index;
    return res;
}