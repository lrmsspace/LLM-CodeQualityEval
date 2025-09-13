/**https://leetcode.com/problems/binary-tree-paths/ */
//Given the root of a binary tree, return all root-to-leaf paths in any order.
//A leaf is a node with no children.
// 
//Example 1:
//Input: root = [1,2,3,null,5]
//Output: ["1->2->5","1->3"]
//Example 2:
//Input: root = [1]
//Output: ["1"]
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 100].
//	-100 <= Node.val <= 100
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
char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    int i, j, k, n, m, l, r, mid, size;
    char **ret, **tmp;
    struct TreeNode *node;
    if (!root) return NULL;
    size = 0;
    ret = malloc(sizeof(char *));
    ret[0] = malloc(sizeof(char) * 32);
    sprintf(ret[0], "%d", root->val);
    size++;
   if (!root->left && !root->right) return ret;
}