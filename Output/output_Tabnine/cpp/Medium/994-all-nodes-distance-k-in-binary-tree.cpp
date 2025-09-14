/**https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/ */
//Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
//You can return the answer in any order.
// 
//Example 1:
//Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
//Output: [7,4,1]
//Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
//Example 2:
//Input: root = [1], target = 1, k = 3
//Output: []
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 500].
//	0 <= Node.val <= 500
//	All the values Node.val are unique.
//	target is the value of one of the nodes in the tree.
//	0 <= k <= 1000
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        unordered_map<TreeNode*, TreeNode*> parent;
        dfs(root, parent);
        queue<TreeNode*> q;
        q.push(target);
        while (!q.empty() && k--) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (i == 0) res.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                if (parent[node]) q.push(parent[node]);
            }
        }
        return res;
        
    }
};