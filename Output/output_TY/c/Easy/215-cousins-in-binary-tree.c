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
bool isCousins(struct TreeNode* root, int x, int y){
    int xDepth = 0, yDepth = 0;
    int xParent = 0, yParent = 0;
    bool xFound = false, yFound = false;
    struct TreeNode* node = root;
    while (node) {
        if (node->left) {
            if (node->left->val == x) {
                xFound = true;
                xDepth = xDepth + 1;
            }
        }
    }
    while (node) {
        if (node->right) {
            if (node->right->val == y) {
                yFound = true;
                yDepth = yDepth + 1;
            }
        }
    }
    while (node) {
        if (node->left) {
            if (node->left->val == x) {
                xParent = node->val;
            }
        }
    }
    while (node) {
        if (node->right) {
            if (node->right->val == y) {
                yParent = node->val;
            }
        }
    }
    return (xFound && yFound &&xDepth == yDepth && xParent != yParent);
}