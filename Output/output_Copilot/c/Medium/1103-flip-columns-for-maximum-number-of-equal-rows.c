/**https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/ */
//You are given an m x n binary matrix matrix.
//You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa).
//Return the maximum number of rows that have all values equal after some number of flips.
// 
//Example 1:
//Input: matrix = [[0,1],[1,1]]
//Output: 1
//Explanation: After flipping no values, 1 row has all values equal.
//Example 2:
//Input: matrix = [[0,1],[1,0]]
//Output: 2
//Explanation: After flipping values in the first column, both rows have equal values.
//Example 3:
//Input: matrix = [[0,0,0],[0,0,1],[1,1,0]]
//Output: 2
//Explanation: After flipping values in the first two columns, the last two rows have equal values.
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 300
//	matrix[i][j] is either 0 or 1.
int maxEqualRowsAfterFlips(int** matrix, int matrixSize, int* matrixColSize) {
    int i, j, k, count, max = 0;
    int *a = (int *)malloc(sizeof(int) * matrixSize);
    for (i = 0; i < matrixSize; i++) {
        count = 0;
        for (j = 0; j < matrixSize; j++) {
            if (matrix[i][0] == matrix[j][0]) {
                for (k = 0; k < *matrixColSize; k++) {
                    if (matrix[i][k] != matrix[j][k]) {
                        break;
                    }
                }
                if (k == *matrixColSize) {
                    count++;
                }
            }
        }
        a[i] = count;
    }
    for (i = 0; i < matrixSize; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;    
}