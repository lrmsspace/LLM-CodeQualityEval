/**https://leetcode.com/problems/all-elements-in-two-binary-search-trees/ */
//Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.
// 
//Example 1:
//Input: root1 = [2,1,4], root2 = [1,0,3]
//Output: [0,1,1,2,3,4]
//Example 2:
//Input: root1 = [1,null,8], root2 = [8,1]
//Output: [1,1,8,8]
// 
//Constraints:
//	The number of nodes in each tree is in the range [0, 5000].
//	-105 <= Node.val <= 105
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result;
        stack<TreeNode*> s1, s2;
        if (root1) s1.push(root1);
        if (root2) s2.push(root2);
        
        while (!s1.empty() || !s2.empty()) {
            stack<TreeNode*> &s = s1.empty() ? s2 : s2.empty() ? s1 : (s1.top()->val < s2.top()->val ? s1 : s2);
            TreeNode* node = s.top(); s.pop();
            result.push_back(node->val);
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
        }
        
        return result;
    }
};