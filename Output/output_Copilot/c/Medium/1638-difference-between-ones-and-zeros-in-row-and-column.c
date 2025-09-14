/**https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/ */
//You are given a 0-indexed m x n binary matrix grid.
//A 0-indexed m x n difference matrix diff is created with the following procedure:
//	Let the number of ones in the ith row be onesRowi.
//	Let the number of ones in the jth column be onesColj.
//	Let the number of zeros in the ith row be zerosRowi.
//	Let the number of zeros in the jth column be zerosColj.
//	diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
//Return the difference matrix diff.
// 
//Example 1:
//Input: grid = [[0,1,1],[1,0,1],[0,0,1]]
//Output: [[0,0,4],[0,0,4],[-2,-2,2]]
//Explanation:
//- diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 2 + 1 - 1 - 2 = 0 
//- diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 2 + 1 - 1 - 2 = 0 
//- diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 2 + 3 - 1 - 0 = 4 
//- diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 2 + 1 - 1 - 2 = 0 
//- diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 2 + 1 - 1 - 2 = 0 
//- diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 2 + 3 - 1 - 0 = 4 
//- diff[2][0] = onesRow2 + onesCol0 - zerosRow2 - zerosCol0 = 1 + 1 - 2 - 2 = -2
//- diff[2][1] = onesRow2 + onesCol1 - zerosRow2 - zerosCol1 = 1 + 1 - 2 - 2 = -2
//- diff[2][2] = onesRow2 + onesCol2 - zerosRow2 - zerosCol2 = 1 + 3 - 2 - 0 = 2
//Example 2:
//Input: grid = [[1,1,1],[1,1,1]]
//Output: [[5,5,5],[5,5,5]]
//Explanation:
//- diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 3 + 2 - 0 - 0 = 5
//- diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 3 + 2 - 0 - 0 = 5
//- diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 3 + 2 - 0 - 0 = 5
//- diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 3 + 2 - 0 - 0 = 5
//- diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 3 + 2 - 0 - 0 = 5
//- diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 3 + 2 - 0 - 0 = 5
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 105
//	1 <= m * n <= 105
//	grid[i][j] is either 0 or 1.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** onesMinusZeros(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int m = gridSize, n = *gridColSize;
    int **diff = (int **)malloc(sizeof(int *) * m);
    *returnColumnSizes = (int *)malloc(sizeof(int) * m);
    *returnSize = m;
    for (int i = 0; i < m; i++) {
        diff[i] = (int *)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    int *onesRow = (int *)malloc(sizeof(int) * m);
    int *onesCol = (int *)malloc(sizeof(int) * n);
    int *zerosRow = (int *)malloc(sizeof(int) * m);
    int *zerosCol = (int *)malloc(sizeof(int) * n);
    memset(onesRow, 0, sizeof(int) * m);
    memset(onesCol, 0, sizeof(int) * n);
    memset(zerosRow, 0, sizeof(int) * m);
    memset(zerosCol, 0, sizeof(int) * n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            onesRow[i] += grid[i][j];
            onesCol[j] += grid[i][j];
            zerosRow[i] += !grid[i][j];
            zerosCol[j] += !grid[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            diff[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
        }
    }
    free(onesRow);
    free(onesCol);
    free(zerosRow);
    free(zerosCol);
    return diff;    
}