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
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int m = matrixSize, n = matrixColSize[0];
    *returnSize = m * n;
    int* ret = (int*)malloc(sizeof(int) * (*returnSize));
    int index = 0;
    int left = 0, right = n - 1, top = 0, bottom = m - 1;
    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; i++) {
            ret[index++] = matrix[top][i];
        }
        for (int i = top + 1; i <= bottom; i++) {
            ret[index++] = matrix[i][right];
        }
        if (left < right && top < bottom) {
            for (int i = right - 1; i >= left; i--) {
                ret[index++] = matrix[bottom][i];
            }
            for (int i = bottom - 1; i > top; i--) {
                ret[index++] = matrix[i][left];
            }
        }
        left++;
        right--;
        top++;
        bottom--;
    }
    return ret;    
}