/**https://leetcode.com/problems/binary-tree-cameras/ */
//You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
//Return the minimum number of cameras needed to monitor all nodes of the tree.
// 
//Example 1:
//Input: root = [0,0,null,0,0]
//Output: 1
//Explanation: One camera is enough to monitor all nodes if placed as shown.
//Example 2:
//Input: root = [0,0,null,0,null,0,null,null,0]
//Output: 2
//Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 1000].
//	Node.val == 0
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
    int minCameraCover(TreeNode* root) {
        int res = 0;
        unordered_map<TreeNode*, int> dp;
        auto dfs = [&](auto&& self, TreeNode* node) -> int {
            if (!node) return 0;
            if (dp.count(node)) return dp[node];
            int left = self(self, node->left);
            int right = self(self, node->right);
            if (left == 0 && right == 0) {
                res++;
                return 1;
            }
            if (left == 0) return 2;
            if (right == 0) return 2;
            return 0;
        };
        dfs(dfs, root);
        return res;
    }
};