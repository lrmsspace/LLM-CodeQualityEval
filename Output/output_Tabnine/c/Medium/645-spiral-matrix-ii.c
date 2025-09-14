/**https://leetcode.com/problems/spiral-matrix-ii/ */
//Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
// 
//Example 1:
//Input: n = 3
//Output: [[1,2,3],[8,9,4],[7,6,5]]
//Example 2:
//Input: n = 1
//Output: [[1]]
// 
//Constraints:
//	1 <= n <= 20
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    
    int count = 1;
    int left = 0, right = n - 1, top = 0, bottom = n - 1;

    while (left <= right && top <= bottom) {
        // Traverse the top row
        for (int i = left; i <= right; i++) {
            matrix[top][i] = count++;
        }
        top++;

        // Traverse the right column
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = count++;
        }
        right--;

        // Traverse the bottom row in reverse order
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = count++;
            }
            bottom--;
        }

        // Traverse the left column in reverse order
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = count++;
            }
            left++;
        }
    }
    
    *returnSize = n;
    return matrix;
    
}