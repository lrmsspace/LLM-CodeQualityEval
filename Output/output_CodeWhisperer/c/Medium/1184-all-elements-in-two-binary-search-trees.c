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
int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 5000);
    int i = 0;
    int j = 0;
    int k = 0;
    int* stack1 = (int*)malloc(sizeof(int) * 5000);
    int* stack2 = (int*)malloc(sizeof(int) * 5000);
    int top1 = -1;
    int top2 = -1;
    while (root1 != NULL || root2 != NULL || top1 != -1 || top2 != -1) {
        while (root1 != NULL) {
            stack1[++top1] = root1->val;
            root1 = root1->left;
        }
        while (root2 != NULL) {
            stack2[++top2] = root2->val;
            root2 = root2->left;
        }
        if (top1 == -1) {
            result[k++] = stack2[top2--];
        }
        else if (top2 == -1) {
            result[k++] = stack1[top1--];
        }
        else if (stack1[top1] < stack2[top2]) {
            result[k++] = stack1[top1--];
        }
        else {
            result[k++] = stack2[top2--];
        }
    }
    *returnSize = k;
    return result;
}