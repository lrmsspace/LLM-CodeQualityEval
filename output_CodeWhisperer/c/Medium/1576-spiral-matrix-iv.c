/**https://leetcode.com/problems/spiral-matrix-iv/ */
//You are given two integers m and n, which represent the dimensions of a matrix.
//You are also given the head of a linked list of integers.
//Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.
//Return the generated matrix.
// 
//Example 1:
//Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
//Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
//Explanation: The diagram above shows how the values are printed in the matrix.
//Note that the remaining spaces in the matrix are filled with -1.
//Example 2:
//Input: m = 1, n = 4, head = [0,1,2]
//Output: [[0,1,2,-1]]
//Explanation: The diagram above shows how the values are printed from left to right in the matrix.
//The last space in the matrix is set to -1.
// 
//Constraints:
//	1 <= m, n <= 105
//	1 <= m * n <= 105
//	The number of nodes in the list is in the range [1, m * n].
//	0 <= Node.val <= 1000
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** spiralMatrix(int m, int n, struct ListNode* head, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * m);
    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        result[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    *returnSize = m;
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    int i = 0, j = 0;
    while (head != NULL) {
        result[i][j] = head->val;
        head = head->next;
        if (i == top && j < right) {
            j++;
        } else if (j == right && i < bottom) {
            i++;
        } else if (i == bottom && j > left) {
            j--;
        } else if (j == left && i > top) {
            i--;
        }
        if (i == top && j == left) {
            top++;
            bottom--;
            left++;
            right--;
            i = top;
            j = left;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (result[i][j] == 0) {
                result[i][j] = -1;
            }
        }
    }
    return result;
}