/**https://leetcode.com/problems/cousins-in-binary-tree/ */
//Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.
//Two nodes of a binary tree are cousins if they have the same depth with different parents.
//Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.
// 
//Example 1:
//Input: root = [1,2,3,4], x = 4, y = 3
//Output: false
//Example 2:
//Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
//Output: true
//Example 3:
//Input: root = [1,2,3,null,4], x = 2, y = 3
//Output: false
// 
//Constraints:
//	The number of nodes in the tree is in the range [2, 100].
//	1 <= Node.val <= 100
//	Each node has a unique value.
//	x != y
//	x and y are exist in the tree.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isCousins(struct TreeNode* root, int x, int y) {
    if (root == NULL) {
        return false;
    }

    struct TreeNode* xParent = NULL;
    struct TreeNode* yParent = NULL;
    int xDepth = -1;
    int yDepth = -1;

    struct TreeNode* stack[100];
    int stackSize = 0;

    struct TreeNode* node = root;
    int depth = 0;

    while (node != NULL || stackSize > 0) {
        while (node != NULL) {
            stack[stackSize++] = node;
            node = node->left;
        }

        node = stack[--stackSize];

        if (node->val == x) {
            xParent = stack[stackSize - 1];
            xDepth = depth;
        } else if (node->val == y) {
            yParent = stack[stackSize - 1];
            yDepth = depth;
        }

        node = node->right;

        if (xParent != NULL && yParent != NULL) {
            break;
        }

        depth++;
    }

    return xDepth == yDepth && xParent != yParent;
    
}