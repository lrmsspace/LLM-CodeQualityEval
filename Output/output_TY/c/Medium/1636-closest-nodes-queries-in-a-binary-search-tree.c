/**https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/ */
//You are given the root of a binary search tree and an array queries of size n consisting of positive integers.
//Find a 2D array answer of size n where answer[i] = [mini, maxi]:
//	mini is the largest value in the tree that is smaller than or equal to queries[i]. If a such value does not exist, add -1 instead.
//	maxi is the smallest value in the tree that is greater than or equal to queries[i]. If a such value does not exist, add -1 instead.
//Return the array answer.
// 
//Example 1:
//Input: root = [6,2,13,1,4,9,15,null,null,null,null,null,null,14], queries = [2,5,16]
//Output: [[2,2],[4,6],[15,-1]]
//Explanation: We answer the queries in the following way:
//- The largest number that is smaller or equal than 2 in the tree is 2, and the smallest number that is greater or equal than 2 is still 2. So the answer for the first query is [2,2].
//- The largest number that is smaller or equal than 5 in the tree is 4, and the smallest number that is greater or equal than 5 is 6. So the answer for the second query is [4,6].
//- The largest number that is smaller or equal than 16 in the tree is 15, and the smallest number that is greater or equal than 16 does not exist. So the answer for the third query is [15,-1].
//Example 2:
//Input: root = [4,null,9], queries = [3]
//Output: [[-1,4]]
//Explanation: The largest number that is smaller or equal to 3 in the tree does not exist, and the smallest number that is greater or equal to 3 is 4. So the answer for the query is [-1,4].
// 
//Constraints:
//	The number of nodes in the tree is in the range [2, 105].
//	1 <= Node.val <= 106
//	n == queries.length
//	1 <= n <= 105
//	1 <= queries[i] <= 106
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** closestNodes(struct TreeNode* root, int* queries, int queriesSize, int* returnSize, int** returnColumnSizes){        
    int* arr = malloc(sizeof(int) * 1000000);
    int* arr2 = malloc(sizeof(int) * 1000000);
    int i, j, k, l, r, mid, n = 0;
    while (root) {
        arr[n++] = root->val;
        if (root->left) {
            for (i = n - 1; i >= 0; i--) {
                arr2[n++] = arr[i];
            }
        }
        root = root->right;
    }
    for (i = 0; i < n; i++) {
        arr2[i] = arr[i];
    }
    *returnSize = queriesSize;
    *returnColumnSizes = malloc(sizeof(int) * queriesSize);
    for (i = 0; i < queriesSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    int** ans = malloc(sizeof(int*) * queriesSize);
    for (i = 0; i < queriesSize; i++) {
        ans[i] = malloc(sizeof(int) * 2);
    }
    for (i = 0; i < queriesSize; i++) {
        l = 0;
        r = n - 1;
        while (l < r) {
            mid = (l + r) / 2;
            if (arr2[mid] < queries[i]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (arr2[l] > queries[i]) {
            l--;
        }
    }
    for (i = 0; i < queriesSize; i++) {
        l = 0;
        r = n - 1;
        while (l < r) {
            mid = (l + r) / 2;
            if (arr2[mid] <= queries[i]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (arr2[l] < queries[i]) {
            l++;
        }
    }
    for (i = 0; i < queriesSize; i++) {
        ans[i][0] = arr2[l];
        ans[i][1] = arr2[r];
    }
    return ans;
}