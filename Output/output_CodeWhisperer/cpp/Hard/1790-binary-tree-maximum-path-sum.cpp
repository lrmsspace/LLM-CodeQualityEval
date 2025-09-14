/**https://leetcode.com/problems/binary-tree-maximum-path-sum/ */
//A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
//The path sum of a path is the sum of the node's values in the path.
//Given the root of a binary tree, return the maximum path sum of any non-empty path.
// 
//Example 1:
//Input: root = [1,2,3]
//Output: 6
//Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
//Example 2:
//Input: root = [-10,9,20,null,null,15,7]
//Output: 42
//Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 3 * 104].
//	-1000 <= Node.val <= 1000
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
        int maxPathSum(TreeNode* root) {
            int maxSum = INT_MIN;
            maxPathSumHelper(root, maxSum);
            return maxSum;
        }
        
    private:
        // Returns the maximum path sum starting from the given node and going down one path
        // Updates maxSum with the maximum path sum that can include the given node as the highest node
        int maxPathSumHelper(TreeNode* node, int& maxSum) {
            // Base case: empty node
            if (!node) return 0;
            
            // Find maximum path sum in left and right subtrees
            // If the path sum is negative, we're better off not including that path
            int leftMax = max(0, maxPathSumHelper(node->left, maxSum));
            int rightMax = max(0, maxPathSumHelper(node->right, maxSum));
            
            // The maximum path sum that includes the current node as the highest node
            // This path can go from left subtree -> current node -> right subtree
            int currentPathSum = node->val + leftMax + rightMax;
            
            // Update the global maximum sum if the current path is better
            maxSum = max(maxSum, currentPathSum);
            
            // Return the maximum sum of a path that can be extended by a parent node
            // This can only include one subtree (left or right) plus the current node
            return node->val + max(leftMax, rightMax);
        }
    };
    