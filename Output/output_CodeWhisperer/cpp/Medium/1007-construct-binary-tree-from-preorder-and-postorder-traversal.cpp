/**https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/ */
//Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.
//If there exist multiple answers, you can return any of them.
// 
//Example 1:
//Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
//Output: [1,2,3,4,5,6,7]
//Example 2:
//Input: preorder = [1], postorder = [1]
//Output: [1]
// 
//Constraints:
//	1 <= preorder.length <= 30
//	1 <= preorder[i] <= preorder.length
//	All the values of preorder are unique.
//	postorder.length == preorder.length
//	1 <= postorder[i] <= postorder.length
//	All the values of postorder are unique.
//	It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if(preorder.size() == 0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        if(preorder.size() == 1) return root;
        int left = preorder[1];
        int i = 0;
        while(postorder[i] != left) i++;
        i++;
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + i + 1);
        vector<int> leftPost(postorder.begin(), postorder.begin() + i);
        root->left = constructFromPrePost(leftPre, leftPost);
        vector<int> rightPre(preorder.begin() + i + 1, preorder.end());
        vector<int> rightPost(postorder.begin() + i, postorder.end() - 1);
        root->right = constructFromPrePost(rightPre, rightPost);
        return root;      
    }
};