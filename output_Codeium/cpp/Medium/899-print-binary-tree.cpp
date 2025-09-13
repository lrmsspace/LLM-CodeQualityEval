/**https://leetcode.com/problems/print-binary-tree/ */
//Given the root of a binary tree, construct a 0-indexed m x n string matrix res that represents a formatted layout of the tree. The formatted layout matrix should be constructed using the following rules:
//	The height of the tree is height and the number of rows m should be equal to height + 1.
//	The number of columns n should be equal to 2height+1 - 1.
//	Place the root node in the middle of the top row (more formally, at location res[0][(n-1)/2]).
//	For each node that has been placed in the matrix at position res[r][c], place its left child at res[r+1][c-2height-r-1] and its right child at res[r+1][c+2height-r-1].
//	Continue this process until all the nodes in the tree have been placed.
//	Any empty cells should contain the empty string "".
//Return the constructed matrix res.
// 
//Example 1:
//Input: root = [1,2]
//Output: 
//[["","1",""],
// ["2","",""]]
//Example 2:
//Input: root = [1,2,3,null,4]
//Output: 
//[["","","","1","","",""],
// ["","2","","","","3",""],
// ["","","4","","","",""]]
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 210].
//	-99 <= Node.val <= 99
//	The depth of the tree will be in the range [1, 10].
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
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getMaxDepth(root);
        int m = height + 1;
        int n = (1 << height) - 1;
        vector<vector<string>> res(m, vector<string>(n, ""));
        fillTree(root, res, 0, 0, n - 1);
        return res;
    }
    
    int getMaxDepth(TreeNode* root) {
        if (!root) return 0;
        int left = getMaxDepth(root->left);
        int right = getMaxDepth(root->right);
        return max(left, right) + 1;
    }
    
    void fillTree(TreeNode* root, vector<vector<string>>& res, int row, int left, int right) {
        if (!root) return;
        int mid = left + (right - left) / 2;
        res[row][mid] = to_string(root->val);
        fillTree(root->left, res, row + 1, left, mid - 1);
        fillTree(root->right, res, row + 1, mid + 1, right);    

    }
};