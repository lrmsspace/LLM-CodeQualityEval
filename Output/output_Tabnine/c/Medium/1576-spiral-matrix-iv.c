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
    int** matrix = (int**)malloc(m * sizeof(int*));
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    
    int left = 0, right = n - 1, top = 0, bottom = m - 1;
    int direction = 0; // 0: right, 1: down, 2: left, 3: up
    int count = 0;              
    
    while (left <= right && top <= bottom) {
        if (direction == 0) {
            for (int i = left; i <= right; i++) {
                matrix[top][i] = head->val;
                head = head->next;
                count++;
                if (count == m * n) {
                    return matrix;
                }
            }
            top++;
            direction = 1;
        } else if (direction == 1) {
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = head->val;
                head = head->next;
                count++;
                if (count == m * n) {
                    return matrix;
                }
            }
            right--;
            direction = 2;
        } else if (direction == 2) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = head->val;
                head = head->next;
                count++;
                if (count == m * n) {
                    return matrix;
                }
            }
            bottom--;
            direction = 3;
        } else {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = head->val;
                head = head->next;
                count++;
                if (count == m * n) {
                    return matrix;
                }
            }
            left++;
            direction = 0;
        }
        
        // Add -1 to fill remaining spaces
        for (int i = left; i <= right && top <= bottom; i++) {
            matrix[top][i] = -1;
            matrix[bottom][i] = -1;
        }
        for (int i = top + 1; i <= bottom - 1 && left <= right; i++) {
            matrix[i][left] = -1;
            matrix[i][right] = -1;
        }
    }
    
    return matrix;
}