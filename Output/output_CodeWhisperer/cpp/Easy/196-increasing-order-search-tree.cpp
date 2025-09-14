/**https://leetcode.com/problems/increasing-order-search-tree/ */
//Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.
// 
//Example 1:
//Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
//Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
//Example 2:
//Input: root = [5,1,7]
//Output: [1,null,5,null,7]
// 
//Constraints:
//	The number of nodes in the given tree will be in the range [1, 100].
//	0 <= Node.val <= 1000
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
    TreeNode* increasingBST(TreeNode* root) {
        if (root == nullptr) return nullptr;
        
        vector<int> values;
        stack<TreeNode*> s;
        s.push(root);
        
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            
            if (node->right != nullptr) s.push(node->right);
            if (node->left != nullptr) s.push(node->left);
            
            values.push_back(node->val);
        }
        
        sort(values.begin(), values.end());
        
        TreeNode* newRoot = new TreeNode(values[0]);
        TreeNode* current = newRoot;
        
        for (int i = 1; i < values.size(); i++) {
            current->right = new TreeNode(values[i]);
            current = current->right;
        }
        
        return newRoot;     
    }
};