/**https://leetcode.com/problems/balance-a-binary-search-tree/ */
//Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
//A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
// 
//Example 1:
//Input: root = [1,null,2,null,3,null,4,null,null]
//Output: [2,1,3,null,null,null,4]
//Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
//Example 2:
//Input: root = [2,1,3]
//Output: [2,1,3]
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
//	1 <= Node.val <= 105
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


        // Helper function to perform in-order traversal and store nodes in an array
        void inOrderTraversal(struct TreeNode* root, struct TreeNode** nodes, int* index) {
            if (root == NULL) {
                return;
            }
            inOrderTraversal(root->left, nodes, index);
            nodes[(*index)++] = root;
            inOrderTraversal(root->right, nodes, index);
        }

        // Helper function to construct a balanced BST from sorted nodes
        struct TreeNode* buildBalancedBST(struct TreeNode** nodes, int start, int end) {
            if (start > end) {
                return NULL;
            }
            int mid = start + (end - start) / 2;
            struct TreeNode* root = nodes[mid];
            root->left = buildBalancedBST(nodes, start, mid - 1);
            root->right = buildBalancedBST(nodes, mid + 1, end);
            return root;
        }

        struct TreeNode* balanceBST(struct TreeNode* root) {
            // Step 1: Perform in-order traversal to get sorted nodes
            struct TreeNode* nodes[10000];
            int index = 0;
            inOrderTraversal(root, nodes, &index);

            // Step 2: Build a balanced BST from the sorted nodes
            return buildBalancedBST(nodes, 0, index - 1);
        }
        