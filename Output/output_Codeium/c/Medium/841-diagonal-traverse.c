/**https://leetcode.com/problems/diagonal-traverse/ */
//Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
// 
//Example 1:
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [1,2,4,7,5,3,6,8,9]
//Example 2:
//Input: mat = [[1,2],[3,4]]
//Output: [1,2,3,4]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 104
//	1 <= m * n <= 104
//	-105 <= mat[i][j] <= 105
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int m = matSize;
    int n = *matColSize;
    int dir[2][2] = {{-1, 1}, {1, -1}}; //up, down
    int* res = (int*)malloc(m * n * sizeof(int));
    int k = 0;
    *returnSize = m * n;
    int i = 0, j = 0;
    int d = 0;
    while (k < m * n) {
        res[k++] = mat[i][j];
        int newi = i + dir[d][0], newj = j + dir[d][1];
        if (newi < 0 || newi >= m || newj < 0 || newj >= n) {
            d = 1 - d;
            newi = i + dir[d][0], newj = j + dir[d][1];
        }
        i = newi, j = newj;
    }
    return res;
}