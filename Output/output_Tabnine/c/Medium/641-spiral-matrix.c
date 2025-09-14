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
    if (!matrix ||!matrixSize ||!matrixColSize ||!returnSize) {
        *returnSize = 0;
        return NULL;
    }
    
    int top = 0, bottom = matrixSize - 1, left = 0, right = matrixColSize[0] - 1;
    int* result = (int*)malloc(matrixSize * matrixColSize[0] * sizeof(int));
    int index = 0;
    
    while (top <= bottom && left <= right) {
        // Traverse right
        for (int i = left; i <= right; i++) {
            result[index++] = matrix[top][i];
        }
        top++;
        
        // Traverse down
        for (int i = top; i <= bottom; i++) {
            result[index++] = matrix[i][right];
        }
        right--;
        
        // Traverse left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result[index++] = matrix[bottom][i];
            }
            bottom--;
        }
        
        // Traverse up
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[index++] = matrix[i][left];
            }
            left++;
        }
    }
    
    *returnSize = index;
    return result;
    
}