/**https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/ */
//You are given the root of a binary tree.
//A ZigZag path for a binary tree is defined as follow:
//	Choose any node in the binary tree and a direction (right or left).
//	If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
//	Change the direction from right to left or from left to right.
//	Repeat the second and third steps until you can't move in the tree.
//Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).
//Return the longest ZigZag path contained in that tree.
// 
//Example 1:
//Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
//Output: 3
//Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
//Example 2:
//Input: root = [1,1,1,null,1,null,null,1,1,null,1]
//Output: 4
//Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).
//Example 3:
//Input: root = [1]
//Output: 0
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 5 * 104].
//	1 <= Node.val <= 100
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int longestZigZag(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int max = 0;
    struct TreeNode* stack[10000];
    int top = 0;
    stack[top++] = root;
    while (top > 0) {
        struct TreeNode* node = stack[--top];
        if (node->left != NULL) {
            stack[top++] = node->left;
            if (node->right != NULL) {
                int left = 1;
                struct TreeNode* temp = node->right;
                while (temp->left != NULL) {
                    left++;
                    temp = temp->left;
                }
                if (left > max) {
                    max = left;
                }
            }
        }
        if (node->right != NULL) {
            stack[top++] = node->right;
            if (node->left != NULL) {
                int right = 1;
                struct TreeNode* temp = node->left;
                while (temp->right != NULL) {
                    right++;
                    temp = temp->right;
                }
                if (right > max) {
                    max = right;
                }
            }
        }
    }
    return max;
}