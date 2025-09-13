/**https://leetcode.com/problems/sort-the-matrix-diagonally/ */
//A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].
//Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.
// 
//Example 1:
//Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
//Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
//Example 2:
//Input: mat = [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
//Output: [[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 100
//	1 <= mat[i][j] <= 100
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** diagonalSort(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
    int m = matSize, n = *matColSize;
    int** res = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        res[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            res[i][j] = mat[i][j];
    }
    for (int k = 0; k < m + n - 1; k++) {
        int x = k < n ? 0 : k - n + 1, y = k < n ? k : 0;
        int cnt = 0, temp[m + n - 1];
        do {
            temp[cnt++] = res[x][y];
            int nx = x + 1, ny = y + 1;
            if (nx < m && ny < n)
                x = nx, y = ny;
            else
                break;
        } while (1);
        cnt = 0;
        while (cnt < m + n - 1) {
            res[x][y] = temp[cnt++];
            int nx = x + 1, ny = y + 1;
            if (nx < m && ny < n)
                x = nx, y = ny;
            else
                break;
        }
    }
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
        (*returnColumnSizes)[i] = n;
    return res;
}