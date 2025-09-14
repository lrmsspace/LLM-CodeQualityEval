/**https://leetcode.com/problems/binary-tree-inorder-traversal/ */
//Given the root of a binary tree, return the inorder traversal of its nodes' values.
// 
//Example 1:
//Input: root = [1,null,2,3]
//Output: [1,3,2]
//Explanation:
//Example 2:
//Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
//Output: [4,2,6,5,7,1,3,9,8]
//Explanation:
//Example 3:
//Input: root = []
//Output: []
//Example 4:
//Input: root = [1]
//Output: [1]
// 
//Constraints:
//	The number of nodes in the tree is in the range [0, 100].
//	-100 <= Node.val <= 100
// 
//Follow up: Recursive solution is trivial, could you do it iteratively?
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    // Initialize stack and result array
    int* result = malloc(sizeof(int) * 100);
    int top = -1;
    
    // Initialize current node as root
    struct TreeNode* current = root;
    
    // Initialize stack and result array
    int* result = malloc(sizeof(int) * 100);
    int top = -1;
    
    // While there are nodes to visit or the stack is not empty
    while (current!= NULL || top!= -1) {
        // Visit all left nodes and push them to the stack
        while (current!= NULL) {
            top++;
            result[top] = current->val;
            current = current->left;
        }
        
        // Pop a node from the stack
        current = stack[top];
        top--;
        
        // Visit the popped node
        result[top + 1] = current->val;
        
        // Move to the right node
        current = current->right;
    }
    
    // Return the result array
    *returnSize = top + 1;
    return result;
}