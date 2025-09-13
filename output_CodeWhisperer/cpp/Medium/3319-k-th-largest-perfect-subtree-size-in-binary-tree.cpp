/*
 You are given the root of a binary tree and an integer k.
 Return an integer denoting the size of the kth largest perfect binary subtree, or -1 if it doesn't exist.
 A perfect binary tree is a tree where all leaves are on the same level, and every parent has two children.
 Example 1:
 Input: root = [5,3,6,5,2,5,7,1,8,null,null,6,8], k = 2
 Output: 3
 Explanation:
 The roots of the perfect binary subtrees are highlighted in black. Their sizes, in non-increasing order are [3, 3, 1, 1, 1, 1, 1, 1].
 The 2nd largest size is 3.
 Example 2:
 Input: root = [1,2,3,4,5,6,7], k = 1
 Output: 7
 Explanation:
 The sizes of the perfect binary subtrees in non-increasing order are [7, 3, 3, 1, 1, 1, 1]. The size of the largest perfect binary subtree is 7.
 Example 3:
 Input: root = [1,2,3,null,4], k = 3
 Output: -1
 Explanation:
 The sizes of the perfect binary subtrees in non-increasing order are [1, 1]. There are fewer than 3 perfect binary subtrees.
 Constraints:
 The number of nodes in the tree is in the range [1, 2000].
 1 <= Node.val <= 2000
 1 <= k <= 1024
*/

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
    // Helper function to check if a subtree is perfect and get its height
    pair<bool, int> isPerfect(TreeNode* root) {
        if (!root) return {true, 0};
        
        auto left = isPerfect(root->left);
        auto right = isPerfect(root->right);
        
        // Perfect tree requires both subtrees to be perfect and have same height
        if (left.first && right.first && left.second == right.second) {
            return {true, left.second + 1};
        }
        return {false, 0};
    }
    
    // Helper function to get size of a perfect tree given its height
    int getSize(int height) {
        return (1 << height) - 1;
    }
    
    void dfs(TreeNode* root, vector<int>& sizes) {
        if (!root) return;
        
        // Check if current subtree is perfect
        auto p = isPerfect(root);
        if (p.first) {
            sizes.push_back(getSize(p.second));
        }
        
        // Recursively check left and right subtrees
        dfs(root->left, sizes);
        dfs(root->right, sizes);
    }
    
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> sizes;
        dfs(root, sizes);
        
        // Sort sizes in descending order
        sort(sizes.rbegin(), sizes.rend());
        
        // Return kth largest if it exists
        if (k <= sizes.size()) {
            return sizes[k-1];
        }
        return -1;
    }
};                    
    