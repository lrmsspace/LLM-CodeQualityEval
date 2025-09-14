/**https://leetcode.com/problems/delete-nodes-and-return-forest/ */
//Given the root of a binary tree, each node in the tree has a distinct value.
//After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
//Return the roots of the trees in the remaining forest. You may return the result in any order.
// 
//Example 1:
//Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
//Output: [[1,2,null,4],[6],[7]]
//Example 2:
//Input: root = [1,2,4,null,3], to_delete = [3]
//Output: [[1,2,4]]
// 
//Constraints:
//	The number of nodes in the given tree is at most 1000.
//	Each node has a distinct value between 1 and 1000.
//	to_delete.length <= 1000
//	to_delete contains distinct values between 1 and 1000.
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
struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize)
{
    struct TreeNode** result = malloc(sizeof(struct TreeNode*) * 1000);
    *returnSize = 0;
    if (root == NULL)
    {
        return result;
    }
    struct TreeNode* stack[1000];
    int stackSize = 0;
    stack[stackSize++] = root;
    while (stackSize > 0)
    {
        struct TreeNode* node = stack[--stackSize];
        if (node->left != NULL)
        {
            stack[stackSize++] = node->left;
        }
        if (node->right != NULL)
        {
            stack[stackSize++] = node->right;
        }
        bool isDelete = false;
        for (int i = 0; i < to_deleteSize; i++)
        {
            if (node->val == to_delete[i])
            {
                isDelete = true;
                break;
            }
        }
        if (isDelete)
        {
            if (node->left != NULL)
            {
                stack[stackSize++] = node->left;
            }
            if (node->right != NULL)
            {
                stack[stackSize++] = node->right;
            }
        }
        else
        {
            if (node->left != NULL && (node->left->left == NULL && node->left->right == NULL))
            {
                node->left = NULL;
            }
            if (node->right != NULL && (node->right->left == NULL && node->right->right == NULL))
            {
                node->right = NULL;
            }
            if (node->left == NULL && node->right == NULL)
            {
                result[*returnSize] = node;
                (*returnSize)++;
            }
        }
    }
    return result;
}