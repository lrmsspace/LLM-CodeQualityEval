/**https://leetcode.com/problems/find-bottom-left-tree-value/ */
//Given the root of a binary tree, return the leftmost value in the last row of the tree.
// 
//Example 1:
//Input: root = [2,1,3]
//Output: 1
//Example 2:
//Input: root = [1,2,3,4,null,5,6,null,null,7]
//Output: 7
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
//	-231 <= Node.val <= 231 - 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findBottomLeftValue(struct TreeNode* root) {
    if (root == NULL) return 0;
    int result = root->val;
    int maxDepth = 0;
    struct TreeNode* queue[10000] = {root}; 
    int front = 0, rear = 1;
    while (front < rear) {
        struct TreeNode* node = queue[front++];
        if (front == rear) {
            maxDepth++;
            result = node->val;
        }
        if (node->left != NULL) queue[rear++] = node->left;
        if (node->right != NULL) queue[rear++] = node->right;
    }
    return result;
}