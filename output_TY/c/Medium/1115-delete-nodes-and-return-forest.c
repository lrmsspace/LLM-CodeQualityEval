/**https://leetcode.com/problems/delete-nodes-and-return-forest/ */
//Given the root of a binary tree, each node in the tree has a distinct value.
//After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
//Return the roots of the trees in the remaining forest. You may return the result in any order.
// 
//Example 1:
//Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
//Output: [[1,2,null,4],[6],[7]]
//Example 2:
//Input: root = [1,2,4,null,3], to_delete = [3]
//Output: [[1,2,4]]
// 
//Constraints:
//	The number of nodes in the given tree is at most 1000.
//	Each node has a distinct value between 1 and 1000.
//	to_delete.length <= 1000
//	to_delete contains distinct values between 1 and 1000.
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
struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize){
    int i;
    for (i = 0; i < to_deleteSize; i++) {
        if (to_delete[i] == root->val) {
            returnSize[0]++;
            return delNodes(root->left, to_delete, to_deleteSize, returnSize) + delNodes(root->right, to_delete, to_deleteSize, returnSize);
        }
    }
    root->left = delNodes(root->left, to_delete, to_deleteSize, returnSize);
    root->right = delNodes(root->right, to_delete, to_deleteSize, returnSize);
    returnSize[0]--;
    returnSize[0] += root->left != NULL || root->right != NULL;
    return (struct TreeNode**)realloc(root, sizeof(struct TreeNode*));
}