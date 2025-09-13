/*
 You are given the root of a binary tree and an integer k.
 Return an integer denoting the size of the kth largest perfect binary subtree, or -1 if it doesn't exist.
 A perfect binary tree is a tree where all leaves are on the same level, and every parent has two children.
 Example 1:
 Input: root = [5,3,6,5,2,5,7,1,8,null,null,6,8], k = 2
 Output: 3
 Explanation:
 The roots of the perfect binary subtrees are highlighted in black. Their sizes, in non-increasing order are [3, 3, 1, 1, 1, 1, 1, 1].
 The 2nd largest size is 3.
 Example 2:
 Input: root = [1,2,3,4,5,6,7], k = 1
 Output: 7
 Explanation:
 The sizes of the perfect binary subtrees in non-increasing order are [7, 3, 3, 1, 1, 1, 1]. The size of the largest perfect binary subtree is 7.
 Example 3:
 Input: root = [1,2,3,null,4], k = 3
 Output: -1
 Explanation:
 The sizes of the perfect binary subtrees in non-increasing order are [1, 1]. There are fewer than 3 perfect binary subtrees.
 Constraints:
 The number of nodes in the tree is in the range [1, 2000].
 1 <= Node.val <= 2000
 1 <= k <= 1024
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int kthLargestPerfectSubtree(struct TreeNode* root, int k) {
    if (!root) return -1;
    int left = kthLargestPerfectSubtree(root->left, k);
    int right = kthLargestPerfectSubtree(root->right, k);
    if (left == -1 && right == -1) {
        struct TreeNode* temp = root;
        int level = 0;
        int count = 1;
        while (temp->left) {
            level++;
            temp = temp->left;
            count *= 2;
        }
        if (count >= k) return (1 << level);
        k -= count;
    }
    if (left != -1 && right != -1) return (left > right) ? left : right;
    return (left != -1) ? left : right;
}