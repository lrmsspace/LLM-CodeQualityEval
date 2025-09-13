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
    
    int *ans = (int *)malloc(100 * sizeof(int));
    int idx = 0;
    struct TreeNode *stack[100];
    int top = 0;
    while (root || top) {
        while (root) {
            stack[top++] = root;
            root = root->left;
        }
        root = stack[--top];
        ans[idx++] = root->val;
        root = root->right;
    }
    *returnSize = idx;
    return ans;
}
