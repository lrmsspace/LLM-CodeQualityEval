/**https://leetcode.com/problems/balance-a-binary-search-tree/ */
//Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
//A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
// 
//Example 1:
//Input: root = [1,null,2,null,3,null,4,null,null]
//Output: [2,1,3,null,null,null,4]
//Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
//Example 2:
//Input: root = [2,1,3]
//Output: [2,1,3]
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
//	1 <= Node.val <= 105
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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return;
            dfs(node->left);
            inorder.push_back(node->val);
            dfs(node->right);
        };
        dfs(root);
        int m = inorder.size() / 2;
        TreeNode* newRoot = new TreeNode(inorder[m]);
        newRoot->left = balanceBSTRec(inorder, 0, m - 1);
        newRoot->right = balanceBSTRec(inorder, m + 1, inorder.size() - 1);
        return newRoot;
    }
    TreeNode* balanceBSTRec(vector<int>& inorder, int start, int end) {
        if (start > end) return nullptr;
        int m = (start + end) / 2;
        TreeNode* node = new TreeNode(inorder[m]);
        node->left = balanceBSTRec(inorder, start, m - 1);
        node->right = balanceBSTRec(inorder, m + 1, end);
        return node;
    }
};