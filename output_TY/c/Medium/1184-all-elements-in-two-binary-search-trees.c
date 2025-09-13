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
int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize){
    int *arr1, *arr2, *arr3;
    int size1, size2, size3;
    size1 = size2 = size3 = 0;
    arr1 = malloc(sizeof(int) * 5000);
    arr2 = malloc(sizeof(int) * 5000);
    arr3 = malloc(sizeof(int) * 10000);
    while (root1 != NULL || root2 != NULL){
        if (root1 != NULL){
            arr1[size1++] = root1->val;
            root1 = root1->left;
        }
    }
    while (root2 != NULL){
        arr2[size2++] = root2->val;
        root2 = root2->left;
    }
    for (int i = 0; i < size1; i++){
        for (int j = 0; j < size2; j++){
            if (arr1[i] <= arr2[j]){
                arr3[size3++] = arr1[i];
                break;
            }
        }
    }
    for (int i = 0; i < size2; i++){
        for (int j = 0; j < size1; j++){
            if (arr2[i] <= arr1[j]){
                arr3[size3++] = arr2[i];
                break;
            }
        }
    }
    *returnSize = size3;
    return arr3;
}