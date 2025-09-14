/**https://leetcode.com/problems/all-elements-in-two-binary-search-trees/ */
//Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.
// 
//Example 1:
//Input: root1 = [2,1,4], root2 = [1,0,3]
//Output: [0,1,1,2,3,4]
//Example 2:
//Input: root1 = [1,null,8], root2 = [8,1]
//Output: [1,1,8,8]
// 
//Constraints:
//	The number of nodes in each tree is in the range [0, 5000].
//	-105 <= Node.val <= 105
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

void inorderTraversal(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) return;
    inorderTraversal(root->left, arr, index);
    arr[(*index)++] = root->val;
    inorderTraversal(root->right, arr, index);
}

int* mergeArrays(int* arr1, int size1, int* arr2, int size2, int* returnSize) {
    int* result = (int*)malloc((size1 + size2) * sizeof(int));
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) result[k++] = arr1[i++];
        else result[k++] = arr2[j++];
    }
    while (i < size1) result[k++] = arr1[i++];
    while (j < size2) result[k++] = arr2[j++];
    *returnSize = k;
    return result;
}

int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize) {
    int arr1[5000], arr2[5000];
    int size1 = 0, size2 = 0;
    inorderTraversal(root1, arr1, &size1);
    inorderTraversal(root2, arr2, &size2);
    
    return mergeArrays(arr1, size1, arr2, size2, returnSize);
}
    