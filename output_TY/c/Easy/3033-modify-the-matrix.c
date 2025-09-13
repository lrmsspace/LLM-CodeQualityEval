/*
 Given a 0-indexed m x n integer matrix matrix, create a new 0-indexed matrix called answer. Make answer equal to matrix, then replace each element with the value -1 with the maximum element in its respective column.
 Return the matrix answer.
 Example 1:
 Input: matrix = [[1,2,-1],[4,-1,6],[7,8,9]]
 Output: [[1,2,9],[4,8,6],[7,8,9]]
 Explanation: The diagram above shows the elements that are changed (in blue).
 - We replace the value in the cell [1][1] with the maximum value in the column 1, that is 8.
 - We replace the value in the cell [0][2] with the maximum value in the column 2, that is 9.
 Example 2:
 Input: matrix = [[3,-1],[5,2]]
 Output: [[3,2],[5,2]]
 Explanation: The diagram above shows the elements that are changed (in blue).
 Constraints:
 m == matrix.length
 n == matrix[i].length
 2 <= m, n <= 50
 -1 <= matrix[i][j] <= 100
 The input is generated such that each column contains at least one non-negative integer.
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** modifiedMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {  
    int i, j, k, l, m, n, max, sum;
    int **a, *b;
    a = (int **)malloc(matrixSize * sizeof(int *));
    b = (int *)malloc(matrixColSize[0] * sizeof(int));
    for (i = 0; i < matrixSize; i++) {
        a[i] = (int *)malloc(matrixColSize[0] * sizeof(int));
        for (j = 0; j < matrixColSize[0]; j++) {
            a[i][j] = matrix[i][j];
        }
    }
    for (i = 0; i < matrixSize; i++) {
        for ( j = 0; j < matrixColSize[0]; j++)
        if (a[i][j] == -1) {
            max = 0;
            for (k = 0; k < matrixSize; k++) {
                if (a[k][j] > max)
                    max = a[k][j];
            }
            a[i][j] = max;
        }
    } 
    for (i = 0; i < matrixSize; i++) {
        sum = 0;
        for (j = 0; j < matrixColSize[0]; j++) {
            sum += a[i][j];
        }
        b[i] = sum;
    }
    *returnSize = matrixSize;
    *returnColumnSizes = b;
    return a;
}