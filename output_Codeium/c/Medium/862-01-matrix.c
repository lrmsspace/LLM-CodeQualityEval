/**https://leetcode.com/problems/01-matrix/ */
//Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
//The distance between two adjacent cells is 1.
// 
//Example 1:
//Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
//Output: [[0,0,0],[0,1,0],[0,0,0]]
//Example 2:
//Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
//Output: [[0,0,0],[0,1,0],[1,2,1]]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 104
//	1 <= m * n <= 104
//	mat[i][j] is either 0 or 1.
//	There is at least one 0 in mat.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = matSize;
    *returnColumnSizes = (int *)malloc(matSize * sizeof(int));
    for (int i = 0; i < matSize; i++) {
        (*returnColumnSizes)[i] = *matColSize;
    }

    int** distances = (int **)malloc(matSize * sizeof(int *));
    for (int i = 0; i < matSize; i++) {
        distances[i] = (int *)malloc((*matColSize) * sizeof(int));
        for (int j = 0; j < *matColSize; j++) {
            distances[i][j] = INT_MAX - 10000;  // Use a large number to avoid overflow
        }
    }
    
    // First pass: check for top and left neighbors
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < *matColSize; j++) {
            if (mat[i][j] == 0) {
                distances[i][j] = 0;
            } else {
                if (i > 0) {
                    distances[i][j] = fmin(distances[i][j], distances[i - 1][j] + 1);
                }
                if (j > 0) {
                    distances[i][j] = fmin(distances[i][j], distances[i][j - 1] + 1);
                }
            }
        }
    }
    
    // Second pass: check for bottom and right neighbors
    for (int i = matSize - 1; i >= 0; i--) {
        for (int j = *matColSize - 1; j >= 0; j--) {
            if (i < matSize - 1) {
                distances[i][j] = fmin(distances[i][j], distances[i + 1][j] + 1);
            }
            if (j < *matColSize - 1) {
                distances[i][j] = fmin(distances[i][j], distances[i][j + 1] + 1);
            }
        }
    }
    
    return distances;

}