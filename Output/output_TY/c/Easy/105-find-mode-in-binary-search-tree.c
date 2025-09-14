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
int* findMode(struct TreeNode* root, int* returnSize){
    int* res = NULL;
    *returnSize = 0;
    if (root == NULL) return res;
    if (root->left == NULL && root->right == NULL) {
        res = (int*)malloc(sizeof(int));
        *returnSize = 1;
        res[0] = root->val;
        return res;
    }
    int* left = findMode(root->left, returnSize);
    int* right = findMode(root->right, returnSize);
    int* cur = (int*)malloc(sizeof(int));
    *returnSize = 1;
    cur[0] = root->val;
    int* res = NULL;
    int i = 0, j = 0, k = 0;
    while (i < *returnSize && j <*returnSize && k < *returnSize) {
        if (left[i] == right[j] && left[i] == cur[k]) {
            res = (int*)realloc(res, sizeof(int) * (*returnSize + 1));
            res[*returnSize] = left[i];
            (*returnSize)++;
            i++;
            j++;
            k++;
        } else if (left[i] == right[j]) {
            res = (int*)realloc(res, sizeof(int) * (*returnSize + 1))
        }
    }
    free(left);
    free(right);
    return res;
}
