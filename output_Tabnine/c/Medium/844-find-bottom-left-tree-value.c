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
    if (!root) return 0;
    
    struct TreeNode* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    int leftmost = root->val;
    
    while (front!= rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            if (node->right) queue[rear++] = node->right;
            if (node->left) queue[rear++] = node->left;
        }
        
        leftmost = queue[front]->val;
    }
    
    return leftmost;
    
}