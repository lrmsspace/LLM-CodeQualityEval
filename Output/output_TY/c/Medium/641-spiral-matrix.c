/**https://leetcode.com/problems/spiral-matrix/ */
//Given an m x n matrix, return all elements of the matrix in spiral order.
// 
//Example 1:
//Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [1,2,3,6,9,8,7,4,5]
//Example 2:
//Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//Output: [1,2,3,4,8,12,11,10,9,5,6,7]
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 10
//	-100 <= matrix[i][j] <= 100
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * matrixSize * matrixColSize[0]);
    int i = 0, j = 0, k = 0;
    int row = matrixSize, col = matrixColSize[0];
    int row_start = 0, row_end = row - 1;
    int col_start = 0, col_end = col - 1;
    while (row_start<= row_end && col_start <= col_end) {
        for (i = col_start; i <= col_end; i++) {
            result[k++] = matrix[row_start][i];
        }
        row_start++;
        for (i = row_start; i <= row_end; i++) {
            result[k++] = matrix[i][col_end];
        }
        col_end--;
        for (i = col_end; i >= col_start;i--) {
            result[k++] = matrix[row_end][i];
        }
        row_end--;
        for (i = row_end; i >= row_start; i--) {
            result[k++] = matrix[i][col_start];
        }
        col_start++;
        }   
    *returnSize = k;
    return result;
}