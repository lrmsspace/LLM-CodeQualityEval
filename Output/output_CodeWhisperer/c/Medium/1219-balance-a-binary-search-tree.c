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
struct TreeNode* balanceBST(struct TreeNode* root) {
    int* nums = (int*)malloc(sizeof(int) * 10000);
    int numsSize = 0;
    void inorder(struct TreeNode* node) {
        if (node == NULL) {
            return;
        }
        inorder(node->left);
        nums[numsSize++] = node->val;
        inorder(node->right);
    }
    inorder(root);
    struct TreeNode* buildBST(int left, int right) {
        if (left > right) {
            return NULL;
        }
        int mid = (left + right) / 2;
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val = nums[mid];
        node->left = buildBST(left, mid - 1);
        node->right = buildBST(mid + 1, right);
        return node;
    }
    return buildBST(0, numsSize - 1);
}