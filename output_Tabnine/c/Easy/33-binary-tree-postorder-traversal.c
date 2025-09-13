/**https://leetcode.com/problems/binary-tree-postorder-traversal/ */
//Given the root of a binary tree, return the postorder traversal of its nodes' values.
// 
//Example 1:
//Input: root = [1,null,2,3]
//Output: [3,2,1]
//Explanation:
//Example 2:
//Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
//Output: [4,6,7,5,2,9,8,3,1]
//Explanation:
//Example 3:
//Input: root = []
//Output: []
//Example 4:
//Input: root = [1]
//Output: [1]
// 
//Constraints:
//	The number of the nodes in the tree is in the range [0, 100].
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
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    
    int leftSize, rightSize;
    int* leftArr = postorderTraversal(root->left, &leftSize);
    int* rightArr = postorderTraversal(root->right, &rightSize);
    
    *returnSize = leftSize + rightSize + 1;
    int* result = malloc(*returnSize * sizeof(int));
    
    int i;
    for (i = 0; i < leftSize; i++) {
        result[i] = leftArr[i];
    }
    result[i++] = root->val;
    for (i = 0; i < rightSize; i++) {
        result[i + leftSize + 1] = rightArr[i];
    }
    
    free(leftArr);
    free(rightArr);
    
    return result;
    
}