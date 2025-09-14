/**https://leetcode.com/problems/matrix-block-sum/ */
//Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:
//	i - k <= r <= i + k,
//	j - k <= c <= j + k, and
//	(r, c) is a valid position in the matrix.
// 
//Example 1:
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
//Output: [[12,21,16],[27,45,33],[24,39,28]]
//Example 2:
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
//Output: [[45,45,45],[45,45,45],[45,45,45]]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n, k <= 100
//	1 <= mat[i][j] <= 100
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixBlockSum(int** mat, int matSize, int* matColSize, int k, int* returnSize, int** returnColumnSizes){
    int i, j, m, n, x, y, sum;
    int **res = malloc(sizeof(int*) * matSize);
    for (i = 0; i < matSize; i++) {
        res[i] = malloc(sizeof(int) * matColSize[i]);
        for (j = 0; j < matColSize[i]; j++) {
            res[i][j] = 0;
        }
    }
    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize[i]; j++) {
            sum = 0;
            for (m = i - k; m <= i + k; m++) {
                for (n = j - k; n <= j + k; n++) {
                    if (m >= 0 && m < matSize && n >= 0 && n < matColSize[i]) {
                        sum += mat[m][n];
                    }
                }
            }
        }
    }
    *returnSize = matSize;
    *returnColumnSizes = malloc(sizeof(int) * matSize);
    for (i = 0; i < matSize; i++) {
        (*returnColumnSizes)[i] = matColSize[i];
    }
    return res;
}