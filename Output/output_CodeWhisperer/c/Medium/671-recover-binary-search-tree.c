/**https://leetcode.com/problems/recover-binary-search-tree/ */
//You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
// 
//Example 1:
//Input: root = [1,3,null,null,2]
//Output: [3,1,null,null,2]
//Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
//Example 2:
//Input: root = [3,1,4,null,null,2]
//Output: [2,1,4,null,null,3]
//Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
// 
//Constraints:
//	The number of nodes in the tree is in the range [2, 1000].
//	-231 <= Node.val <= 231 - 1
// 
//Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void recoverTree(struct TreeNode* root) {
    struct TreeNode* pre = NULL;
    struct TreeNode* first = NULL;
    struct TreeNode* second = NULL;
    struct TreeNode* temp = NULL;
    while (root != NULL) {
        if (root->left != NULL) {
            temp = root->left;
            while (temp->right != NULL && temp->right != root) {
                temp = temp->right;
            }
            if (temp->right == NULL) {
                temp->right = root;
                root = root->left;
            } else {
                if (pre != NULL && pre->val > root->val) {
                    if (first == NULL) {
                        first = pre;
                    }
                    second = root;
                }
                pre = root;
                temp->right = NULL;
                root = root->right;
            }
        } else {
            if (pre != NULL && pre->val > root->val) {
                if (first == NULL) {
                    first = pre;
                }
                second = root;
            }
            pre = root;
            root = root->right;
        }
    }
    if (first != NULL && second != NULL) {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    else if (first != NULL && second == NULL) {
        int temp = first->val;
        first->val = root->val;
        root->val = temp;
    }
    else if (first == NULL && second != NULL) {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }

    else {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }

        
}