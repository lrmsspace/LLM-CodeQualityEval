/**https://leetcode.com/problems/unique-binary-search-trees-ii/ */
//Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
// 
//Example 1:
//Input: n = 3
//Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
//Example 2:
//Input: n = 1
//Output: [[1]]
// 
//Constraints:
//	1 <= n <= 8
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        
        function<vector<TreeNode*>(int, int)> generate = [&](int start, int end) {
            vector<TreeNode*> trees;
            if (start > end) {
                trees.push_back(nullptr);
                return trees;
            }
            
            for (int i = start; i <= end; ++i) {
                vector<TreeNode*> leftTrees = generate(start, i - 1);
                vector<TreeNode*> rightTrees = generate(i + 1, end);
                
                for (auto left : leftTrees) {
                    for (auto right : rightTrees) {
                        TreeNode* root = new TreeNode(i);
                        root->left = left;
                        root->right = right;
                        trees.push_back(root);
                    }
                }
            }
            return trees;
        };
        
        return generate(1, n);

    }
};