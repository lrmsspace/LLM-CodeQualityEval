/**https://leetcode.com/problems/cousins-in-binary-tree/ */
//Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.
//Two nodes of a binary tree are cousins if they have the same depth with different parents.
//Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.
// 
//Example 1:
//Input: root = [1,2,3,4], x = 4, y = 3
//Output: false
//Example 2:
//Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
//Output: true
//Example 3:
//Input: root = [1,2,3,null,4], x = 2, y = 3
//Output: false
// 
//Constraints:
//	The number of nodes in the tree is in the range [2, 100].
//	1 <= Node.val <= 100
//	Each node has a unique value.
//	x != y
//	x and y are exist in the tree.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isCousins(struct TreeNode* root, int x, int y) {
    struct TreeNode* queue[100];
    int front = 0, rear = 0;
    int x_parent = 0, y_parent = 0;
    int x_depth = 0, y_depth = 0;
    int depth = 0;
    queue[rear++] = root;
    while (front < rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            if (node->left) {
                queue[rear++] = node->left;
                if (node->left->val == x) {
                    x_parent = node->val;
                    x_depth = depth + 1;
                }
                if (node->left->val == y) {
                    y_parent = node->val;
                    y_depth = depth + 1;
                }
            }
            if (node->right) {
                queue[rear++] = node->right;
                if (node->right->val == x) {
                    x_parent = node->val;
                    x_depth = depth + 1;
                }
                if (node->right->val == y) {
                    y_parent = node->val;
                    y_depth = depth + 1;
                }
            }
        }
        depth++;
    }
    return x_depth == y_depth && x_parent != y_parent;    
}