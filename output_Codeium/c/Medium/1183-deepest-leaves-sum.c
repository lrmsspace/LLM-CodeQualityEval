/**https://leetcode.com/problems/deepest-leaves-sum/ */
//Given the root of a binary tree, return the sum of values of its deepest leaves.
// 
//Example 1:
//Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
//Output: 15
//Example 2:
//Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
//Output: 19
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
//	1 <= Node.val <= 100
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */ 
void dfs(struct TreeNode* node, int depth, int* maxDepth, int* sum) {
    if (!node) return;

    if (depth > *maxDepth) {
        *maxDepth = depth;
        *sum = node->val;
    } else if (depth == *maxDepth) {
        *sum += node->val;
    }

    dfs(node->left, depth + 1, maxDepth, sum);
    dfs(node->right, depth + 1, maxDepth, sum);
}
int deepestLeavesSum(struct TreeNode* root) {
    if (!root) return 0;

int maxDepth = 0, sum = 0;
dfs(root, 0, &maxDepth, &sum);
return sum; 

}