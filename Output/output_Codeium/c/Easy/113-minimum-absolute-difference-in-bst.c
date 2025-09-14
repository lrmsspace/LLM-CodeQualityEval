/**https://leetcode.com/problems/minimum-absolute-difference-in-bst/ */
//Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
// 
//Example 1:
//Input: root = [4,2,6,1,3]
//Output: 1
//Example 2:
//Input: root = [1,0,48,null,null,12,49]
//Output: 1
// 
//Constraints:
//	The number of nodes in the tree is in the range [2, 104].
//	0 <= Node.val <= 105
// 
//Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */ 
int getMinimumDifference(struct TreeNode* root) {
    int min = INT_MAX;
    struct TreeNode* prev = NULL;
    struct TreeNode* curr = root;
    while (curr) {
        if (curr->left) {
            struct TreeNode* p = curr->left;
            while (p->right) p = p->right;
            p->right = curr;
            struct TreeNode* temp = curr->left;
            curr->left = NULL;
            curr = temp;
        } else {
            if (prev) min = fmin(min, curr->val - prev->val);
            prev = curr;
            curr = curr->right;
        }
    }
    return min;
}
