/**https://leetcode.com/problems/balance-a-binary-search-tree/ */
//Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
//A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
// 
//Example 1:
//Input: root = [1,null,2,null,3,null,4,null,null]
//Output: [2,1,3,null,null,null,4]
//Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
//Example 2:
//Input: root = [2,1,3]
//Output: [2,1,3]
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
//	1 <= Node.val <= 105
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* balanceBST(struct TreeNode* root) {
    if (!root) return NULL;
    
    struct TreeNode* dummy = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    dummy->val = root->val;
    dummy->left = dummy->right = NULL;
    
    struct TreeNode* prev = dummy;
    struct TreeNode* cur = root;
    while (cur) {
        if (cur->left) {
            prev->right = cur->left;
            prev = prev->right;
        }
        cur = cur->right;
    }
    prev->right = NULL;
    
    struct TreeNode* root1 = dummy->right;
    struct TreeNode* root2 = balanceBST(root->right);
    struct TreeNode* root3 = balanceBST(root->left);
    
    dummy->right = root1;
    root1->left = root3;
    root1->right = root2;
    
    return dummy->right;
}