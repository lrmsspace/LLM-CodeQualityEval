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
    int count = 0;
    int max = 0;
    int mode = root->val;
    int* res = (int*)malloc(sizeof(int));
    *returnSize = 1;
    res[0] = root->val;
    // Traverse the tree and count the occurrence of each node
    struct TreeNode* curr = root;
    while (curr) {
        if (curr->val == mode) {
            count++;
            if (count > max) {
                max = count;
                res = (int*)realloc(res, sizeof(int));
                res[0] = mode;
                *returnSize = 1;
            }
        } else {
            if (count == max) {
                res = (int*)realloc(res, (*returnSize + 1) * sizeof(int));
                res[(*returnSize)++] = curr->val;
            }
            mode = curr->val;
            count = 1;
        }
        if (curr->left) curr = curr->left;
        else curr = curr->right;
    }
    if (count == max) {
        res = (int*)realloc(res, (*returnSize + 1) * sizeof(int));
        res[(*returnSize)++] = mode;
    }
    return res;

}