/**https://leetcode.com/problems/same-tree/ */
//Given the roots of two binary trees p and q, write a function to check if they are the same or not.
//Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
// 
//Example 1:
//Input: p = [1,2,3], q = [1,2,3]
//Output: true
//Example 2:
//Input: p = [1,2], q = [1,null,2]
//Output: false
//Example 3:
//Input: p = [1,2,1], q = [1,1,2]
//Output: false
// 
//Constraints:
//	The number of nodes in both trees is in the range [0, 100].
//	-104 <= Node.val <= 104
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p &&!q) return true;
        if (!p ||!q) return false;
        
        if (p->val!= q->val) return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);  // Recursively check the left and right subtrees.  If any pair of subtrees differ, return false.  
        // If all pairs of subtrees match, return true.  The function will return false as soon as it encounters a pair of subtrees that differ.  If all pairs of subtrees match, it will return true at the end.  
        // This approach reduces the time complexity from O(n^2) to O(n), where n is the total number of nodes in the trees.
        
    }
};