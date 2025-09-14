/**https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/ */
//Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.
//Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.
//Note that you need to maximize the answer before taking the mod and not after taking it.
// 
//Example 1:
//Input: root = [1,2,3,4,5,6]
//Output: 110
//Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
//Example 2:
//Input: root = [1,null,2,3,4,null,null,5,6]
//Output: 90
//Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)
// 
//Constraints:
//	The number of nodes in the tree is in the range [2, 5 * 104].
//	1 <= Node.val <= 104
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxProduct(struct TreeNode* root) {
    
    const int MOD = 1000000007;
    long totalSum = 0, maxProductResult = 0;

    // Helper function to calculate total sum of tree
    long calculateTotalSum(struct TreeNode* node) {
        if (!node) return 0;
        long sum = node->val + calculateTotalSum(node->left) + calculateTotalSum(node->right);
        totalSum += node->val;
        return sum;
    }

    // Helper function to find maximum product
    long findMaxProduct(struct TreeNode* node) {
        if (!node) return 0;
        long leftSum = findMaxProduct(node->left);
        long rightSum = findMaxProduct(node->right);
        long subtreeSum = leftSum + rightSum + node->val;
        maxProductResult = fmax(maxProductResult, subtreeSum * (totalSum - subtreeSum));
        return subtreeSum;
    }

    totalSum = calculateTotalSum(root);
    findMaxProduct(root);
    return maxProductResult % MOD;

}   