/**https://leetcode.com/problems/flatten-binary-tree-to-linked-list/ */
//Given the root of a binary tree, flatten the tree into a "linked list":
//	The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
//	The "linked list" should be in the same order as a pre-order traversal of the binary tree.
// 
//Example 1:
//Input: root = [1,2,5,3,4,null,6]
//Output: [1,null,2,null,3,null,4,null,5,null,6]
//Example 2:
//Input: root = []
//Output: []
//Example 3:
//Input: root = [0]
//Output: [0]
// 
//Constraints:
//	The number of nodes in the tree is in the range [0, 2000].
//	-100 <= Node.val <= 100
// 
//Follow up: Can you flatten the tree in-place (with O(1) extra space)?
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    struct TreeNode* current = root;
    while (current) {
        if (current->left) {
            struct TreeNode* next = current->left;
            while (next->right) next = next->right;
            next->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        current = current->right;
    }
    // Helper function to flatten the tree in-place
    void flattenHelper(struct TreeNode* node) {
        if (!node ||!node->left &&!node->right) return;
        flattenHelper(node->right);
        flattenHelper(node->left);
        struct TreeNode* temp = node->right;
        node->right = node->left;
        node->left = NULL;
        while (node->right) node = node->right;
        node->right = temp;
    }
    flattenHelper(root);
    // Convert the flattened tree back to a linked list
    // Create a dummy node
    struct TreeNode* dummy = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    dummy->val = 0;
    dummy->left = root;
    dummy->right = NULL;
    // Traverse the linked list and insert nodes
    struct TreeNode* prev = dummy;
    while (prev->right) {
        prev = prev->right;
        if (prev->left) {
            struct TreeNode* temp = prev->left;
            while (temp->right) temp = temp->right;
            temp->right = prev->right;
            prev->right = prev->left;
            prev->left = NULL;
        }
    }
    // Free the dummy node
    free(dummy);
    // Return the head of the flattened linked list
    return root;
}