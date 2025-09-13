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
        vector<string> res;
        if (root == nullptr) return res;
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(to_string(root->val));
            return res;
        }
        vector<string> left = binaryTreePaths(root->left);
        for (int i = 0; i < left.size(); i++) {
            res.push_back(to_string(root->val) + "->" + left[i]);
        }
        vector<string> right = binaryTreePaths(root->right);
        for (int i = 0; i < right.size(); i++) {
            res.push_back(to_string(root->val) + "->" + right[i]);
        }
        return res        
    }
};