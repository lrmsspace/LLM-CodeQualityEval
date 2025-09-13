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
    int m = matSize, n = matColSize[0];
    int** dist = (int**)malloc(sizeof(int*) * m);
    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        dist[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
        for (int j = 0; j < n; j++) {
            dist[i][j] = mat[i][j] == 0 ? 0 : INT_MAX - 1;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i - 1 >= 0) {
                dist[i][j] = fmin(dist[i][j], dist[i - 1][j] + 1);
            }
            if (j - 1 >= 0) {
                dist[i][j] = fmin(dist[i][j], dist[i][j - 1] + 1);
            }
        }
    }
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i + 1 < m) {
                dist[i][j] = fmin(dist[i][j], dist[i + 1][j] + 1);
            }
            if (j + 1 < n) {
                dist[i][j] = fmin(dist[i][j], dist[i][j + 1] + 1);
            }
        }
    }
    *returnSize = m;
    return dist;
}