/**https://leetcode.com/problems/smallest-string-starting-from-leaf/ */
//You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.
//Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.
//As a reminder, any shorter prefix of a string is lexicographically smaller.
//	For example, "ab" is lexicographically smaller than "aba".
//A leaf of a node is a node that has no children.
// 
//Example 1:
//Input: root = [0,1,2,3,4,3,4]
//Output: "dba"
//Example 2:
//Input: root = [25,1,3,1,3,0,2]
//Output: "adz"
//Example 3:
//Input: root = [2,2,1,null,1,0,null,0]
//Output: "abc"
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 8500].
//	0 <= Node.val <= 25
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
char* smallestFromLeaf(struct TreeNode* root) {
    char* res = "";
    char* path = "";
    dfs(root, &res, &path);
    return res;
}

void dfs(struct TreeNode* node, char** res, char** path) {
    if (!node->left && !node->right) {
        int len = strlen(*path);
        for (int i = len - 1; i >= 0; i--) {
            (*res)[len - i - 1] = (*path)[i] + 'a';
        }
        (*res)[len] = '\0';
        if (strcmp(*res, "") == 0 || strcmp(*res, *path) < 0) {
            strcpy(*res, *path);
        }
        return;
    }

    if (node->left) {
        int len = strlen(*path);
        (*path)[len] = node->val + 'a';
        (*path)[len + 1] = '\0';
        dfs(node->left, res, path);
        (*path)[len] = '\0';
    }

    if (node->right) {
        int len = strlen(*path);
        (*path)[len] = node->val + 'a';
        (*path)[len + 1] = '\0';
        dfs(node->right, res, path);
        (*path)[len] = '\0';
    }
    
}