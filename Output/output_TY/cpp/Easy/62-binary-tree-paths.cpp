/**https://leetcode.com/problems/binary-tree-paths/ */
//Given the root of a binary tree, return all root-to-leaf paths in any order.
//A leaf is a node with no children.
// 
//Example 1:
//Input: root = [1,2,3,null,5]
//Output: ["1->2->5","1->3"]
//Example 2:
//Input: root = [1]
//Output: ["1"]
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 100].
//	-100 <= Node.val <= 100
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;
        if(!root->left && !root->right) return {to_string(root->val)};
        for(auto s : binaryTreePaths(root->left)){
            ans.push_back(to_string(root->val) + "->" + s);
        }
        for(auto s : binaryTreePaths(root->right)){
            ans.push_back(to_string(root->val) + "->" + s);
        }
        return ans;
    }
};