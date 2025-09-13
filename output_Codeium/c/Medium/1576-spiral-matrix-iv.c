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
    *returnSize = m;
    *returnColumnSizes = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
    }
    int **matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
    
    int num = 0;
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            if (head == NULL) matrix[top][i] = -1;
            else matrix[top][i] = head->val, head = head->next;
            num++;
        }
        top++;
        if (num == m * n) break;
        for (int i = top; i <= bottom; i++) {
            if (head == NULL) matrix[i][right] = -1;
            else matrix[i][right] = head->val, head = head->next;
            num++;
        }
        right--;
        if (num == m * n) break;
        for (int i = right; i >= left; i--) {
            if (head == NULL) matrix[bottom][i] = -1;
            else matrix[bottom][i] = head->val, head = head->next;
            num++;
        }
        bottom--;
        if (num == m * n) break;
        for (int i = bottom; i >= top; i--) {
            if (head == NULL) matrix[i][left] = -1;
            else matrix[i][left] = head->val, head = head->next;
            num++;
        }
        left++;
        if (num == m * n) break;
    }
    
    return matrix;
}