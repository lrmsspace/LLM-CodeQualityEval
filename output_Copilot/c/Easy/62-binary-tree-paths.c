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
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    char** left = binaryTreePaths(root->left, returnSize);
    char** right = binaryTreePaths(root->right, returnSize);
    int leftSize = *returnSize;
    int rightSize = *returnSize;
    int size = leftSize + rightSize;
    char** result = (char**)malloc(sizeof(char*) * size);
    for (int i = 0; i < leftSize; i++) {
        result[i] = (char*)malloc(sizeof(char) * 1000);
        sprintf(result[i], "%d->%s", root->val, left[i]);
        free(left[i]);
    }
    for (int i = 0; i < rightSize; i++) {
        result[leftSize + i] = (char*)malloc(sizeof(char) * 1000);
        sprintf(result[leftSize + i], "%d->%s", root->val, right[i]);
        free(right[i]);
    }
    *returnSize = size;
    if (size == 0) {
        result[0] = (char*)malloc(sizeof(char) * 1000);
        sprintf(result[0], "%d", root->val);
        *returnSize = 1;
    }
    return result;    
}