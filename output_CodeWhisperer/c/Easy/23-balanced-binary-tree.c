/**https://leetcode.com/problems/balanced-binary-tree/ */
//Given a binary tree, determine if it is height-balanced.
// 
//Example 1:
//Input: root = [3,9,20,null,null,15,7]
//Output: true
//Example 2:
//Input: root = [1,2,2,3,3,null,null,4,4]
//Output: false
//Example 3:
//Input: root = []
//Output: true
// 
//Constraints:
//	The number of nodes in the tree is in the range [0, 5000].
//	-104 <= Node.val <= 104
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isBalanced(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    int leftHeight = 0;
    int rightHeight = 0;
    if (root->left != NULL) {
        leftHeight = 1 + getHeight(root->left);
    }
    if (root->right != NULL) {
        rightHeight = 1 + getHeight(root->right);
    }
    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
    
}