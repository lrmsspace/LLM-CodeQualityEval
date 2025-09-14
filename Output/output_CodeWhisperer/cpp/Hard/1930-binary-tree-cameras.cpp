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
            int cameras = 0;
            // 0: Not monitored
            // 1: Has camera
            // 2: Monitored (but no camera)
            int rootState = dfs(root, cameras);
            
            // If the root is not monitored after the DFS, we need to add a camera
            return cameras + (rootState == 0 ? 1 : 0);
        }
        
    private:
        // Returns the state of the current node
        int dfs(TreeNode* node, int& cameras) {
            // Base case: null nodes are considered monitored (to avoid placing cameras for leaves)
            if (!node) return 2;
            
            // Post-order traversal: process children first
            int leftState = dfs(node->left, cameras);
            int rightState = dfs(node->right, cameras);
            
            // Case 1: If either child is not monitored, we must place a camera at current node
            if (leftState == 0 || rightState == 0) {
                cameras++;
                return 1; // This node now has a camera
            }
            
            // Case 2: If either child has a camera, current node is monitored
            if (leftState == 1 || rightState == 1) {
                return 2; // This node is monitored (but no camera)
            }
            
            // Case 3: Both children are monitored but don't have cameras
            return 0; // This node is not monitored
        }
    };
    