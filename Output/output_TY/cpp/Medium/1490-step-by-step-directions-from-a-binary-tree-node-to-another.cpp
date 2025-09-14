/**https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/ */
//You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.
//Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:
//	'L' means to go from a node to its left child node.
//	'R' means to go from a node to its right child node.
//	'U' means to go from a node to its parent node.
//Return the step-by-step directions of the shortest path from node s to node t.
// 
//Example 1:
//Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
//Output: "UURL"
//Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
//Example 2:
//Input: root = [2,1], startValue = 2, destValue = 1
//Output: "L"
//Explanation: The shortest path is: 2 → 1.
// 
//Constraints:
//	The number of nodes in the tree is n.
//	2 <= n <= 105
//	1 <= Node.val <= n
//	All the values in the tree are unique.
//	1 <= startValue, destValue <= n
//	startValue != destValue
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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string ans;
        TreeNode* start = nullptr;
        TreeNode* dest = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur->val == startValue){
                start = cur;
            }
            if(cur->val == destValue){
                dest = cur;
            }
            if(cur->left){
                cur->left->parent = cur;
                q.push(cur->left);
            }
            if(cur->right){
                cur->right->parent = cur;
                q.push(cur->right);
            }
        }
        while(dest){
            if(dest == start){
                break;
            }
            if(dest->parent == start->parent->left){
                ans += "U";
            }else{
                if(dest->val > start->val){
                    ans += "R";
                }else{
                    ans += "L";
                }
            }
            dest = dest->parent;
            start = start->parent;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};