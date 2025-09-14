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
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize){
    int m = matSize, n = matColSize[0];
    int *res = (int *)malloc(sizeof(int) * m * n);
    *returnSize = m * n;
    int i = 0, j = 0;
    for (int k = 0; k < m * n; k++) {
        res[k] = mat[i][j];
    }
    for (int k = 0; k < m * n; k++) {
        if ((i + j) % 2 == 0) {
            if (j == n - 1) {
                i++;
            } else if (i == 0) {
                j++;
            } else {
                i--;
                j++;
            }
        } else {
            if (i == m - 1) {
                j++;
            } else if (j == 0){
                i++;
            }
        }
    }
    return res;
}