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
        vector<int> nums;
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) return;
            inorder(node->left);
            nums.push_back(node->val);
            inorder(node->right);
        };
        inorder(root);
        function<TreeNode*(int, int)> build = [&](int start, int end) {
            if (start > end) return (TreeNode*)nullptr;
            int mid = (start + end) / 2;
            TreeNode* node = new TreeNode(nums[mid]);
            node->left = build(start, mid - 1);
            node->right = build(mid + 1, end);
            return node;
        };
        return build(0, nums.size() - 1);      
    }
};