/**https://leetcode.com/problems/house-robber-iii/ */
//The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.
//Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.
//Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
// 
//Example 1:
//Input: root = [3,2,3,null,3,null,1]
//Output: 7
//Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
//Example 2:
//Input: root = [3,4,5,1,3,null,1]
//Output: 9
//Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
//	0 <= Node.val <= 104
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
        int rob(TreeNode* root) {
            pair<int, int> result = robHelper(root);
            return max(result.first, result.second);
        }
        
    private:
        // Returns pair<int, int> where:
        // first = maximum amount if we rob this node
        // second = maximum amount if we don't rob this node
        pair<int, int> robHelper(TreeNode* node) {
            if (node == nullptr) {
                return {0, 0};
            }
            
            // Get results from left and right subtrees
            pair<int, int> left = robHelper(node->left);
            pair<int, int> right = robHelper(node->right);
            
            // If we rob this node, we can't rob its children
            int robCurrent = node->val + left.second + right.second;
            
            // If we don't rob this node, we can choose the maximum from its children
            int skipCurrent = max(left.first, left.second) + max(right.first, right.second);
            
            return {robCurrent, skipCurrent};
        }
    };
    
