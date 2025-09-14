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

    *returnSize = 1;
    char** res = malloc(sizeof(char*));
    res[0] = NULL;
    if (root->left == NULL && root->right == NULL) {
        res[0] = malloc(12);
        sprintf(res[0], "%d", root->val);
        return res;
    }

    int leftSize = 0;
    char** left = binaryTreePaths(root->left, &leftSize);
    int rightSize = 0;
    char** right = binaryTreePaths(root->right, &rightSize);

    *returnSize = leftSize + rightSize;
    res = realloc(res, sizeof(char*) * (*returnSize));
    int j = 0;
    for (int i = 0; i < leftSize; i++) {
        res[j] = malloc(strlen(left[i]) + 4);
        sprintf(res[j++], "%d->%s", root->val, left[i]);
    }
    for (int i = 0; i < rightSize; i++) {
        res[j] = malloc(strlen(right[i]) + 4);
        sprintf(res[j++], "%d->%s", root->val, right[i]);
    }

    return res;
}