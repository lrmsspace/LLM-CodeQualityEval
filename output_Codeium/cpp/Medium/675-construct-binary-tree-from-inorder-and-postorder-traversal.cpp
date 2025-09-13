/**https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/ */
//Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
// 
//Example 1:
//Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
//Output: [3,9,20,null,null,15,7]
//Example 2:
//Input: inorder = [-1], postorder = [-1]
//Output: [-1]
// 
//Constraints:
//	1 <= inorder.length <= 3000
//	postorder.length == inorder.length
//	-3000 <= inorder[i], postorder[i] <= 3000
//	inorder and postorder consist of unique values.
//	Each value of postorder also appears in inorder.
//	inorder is guaranteed to be the inorder traversal of the tree.
//	postorder is guaranteed to be the postorder traversal of the tree.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) return nullptr;
        
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }

        function<TreeNode*(int, int, int, int)> build = [&](int inStart, int inEnd, int postStart, int postEnd) -> TreeNode* {
            if (inStart > inEnd || postStart > postEnd) return nullptr;
            TreeNode* root = new TreeNode(postorder[postEnd]);
            int inRoot = inorder_map[root->val];
            int leftTreeSize = inRoot - inStart;

            root->left = build(inStart, inRoot - 1, postStart, postStart + leftTreeSize - 1);
            root->right = build(inRoot + 1, inEnd, postStart + leftTreeSize, postEnd - 1);
            return root;
        };
        
        return build(0, inorder.size() - 1, 0, postorder.size() - 1);

    }
};