/**https://leetcode.com/problems/longest-univalue-path/ */
//Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.
//The length of the path between two nodes is represented by the number of edges between them.
// 
//Example 1:
//Input: root = [5,4,5,1,1,null,5]
//Output: 2
//Explanation: The shown image shows that the longest path of the same value (i.e. 5).
//Example 2:
//Input: root = [1,4,5,4,4,null,5]
//Output: 2
//Explanation: The shown image shows that the longest path of the same value (i.e. 4).
// 
//Constraints:
//	The number of nodes in the tree is in the range [0, 104].
//	-1000 <= Node.val <= 1000
//	The depth of the tree will not exceed 1000.
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
        int longestUnivaluePath(TreeNode* root) {
            int maxLength = 0;
            dfs(root, maxLength);
            return maxLength;
        }
        
    private:
        // Returns the length of the longest univalue path starting from this node and going downward
        int dfs(TreeNode* node, int& maxLength) {
            if (!node) {
                return 0;
            }
            
            // Recursively find the longest paths in left and right subtrees
            int leftLength = dfs(node->left, maxLength);
            int rightLength = dfs(node->right, maxLength);
            
            // Initialize lengths of paths going through left and right children
            int leftPathLength = 0;
            int rightPathLength = 0;
            
            // If left child exists and has the same value, extend the path
            if (node->left && node->left->val == node->val) {
                leftPathLength = leftLength + 1;
            }
            
            // If right child exists and has the same value, extend the path
            if (node->right && node->right->val == node->val) {
                rightPathLength = rightLength + 1;
            }
            
            // Update the maximum length considering a path that goes through this node
            maxLength = max(maxLength, leftPathLength + rightPathLength);
            
            // Return the longer of the two paths starting from this node
            return max(leftPathLength, rightPathLength);
        }
    };
    