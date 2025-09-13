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
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char** result = (char**)malloc(sizeof(char*) * 100);
    *returnSize = 0;
    if (root == NULL) {
        return result;
    }
    char* path = (char*)malloc(sizeof(char) * 100);
    path[0] = '\0';
    binaryTreePathsHelper(root, path, result, returnSize);
    return result;

    
}