/**https://leetcode.com/problems/find-mode-in-binary-search-tree/ */
//Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.
//If the tree has more than one mode, return them in any order.
//Assume a BST is defined as follows:
//	The left subtree of a node contains only nodes with keys less than or equal to the node's key.
//	The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
//	Both the left and right subtrees must also be binary search trees.
// 
//Example 1:
//Input: root = [1,null,2,2]
//Output: [2]
//Example 2:
//Input: root = [0]
//Output: [0]
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
//	-105 <= Node.val <= 105
// 
//Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int count = 0, maxCount = 0, pre = INT_MIN;
        inorder(root, res, count, maxCount, pre);
        return res;
        
    }
    
    void inorder(TreeNode* root, vector<int>& res, int& count, int& maxCount, int& pre) {
        if (root == nullptr) return;
        
        inorder(root->left, res, count, maxCount, pre);
        
        if (root->val == pre) {
            count++;
        } else {
            count = 1;
        }
        
        if (count > maxCount) {
            maxCount = count;
            res.clear();
            res.push_back(root->val);
        } else if (count == maxCount) {
            res.push_back(root->val);
        }
        
        pre = root->val;
        
        inorder(root->right, res, count, maxCount, pre);
    }
    
        
};