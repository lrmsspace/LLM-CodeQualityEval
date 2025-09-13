/**https://leetcode.com/problems/spiral-matrix-iii/ */
//You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.
//You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.
//Return an array of coordinates representing the positions of the grid in the order you visited them.
// 
//Example 1:
//Input: rows = 1, cols = 4, rStart = 0, cStart = 0
//Output: [[0,0],[0,1],[0,2],[0,3]]
//Example 2:
//Input: rows = 5, cols = 6, rStart = 1, cStart = 4
//Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
// 
//Constraints:
//	1 <= rows, cols <= 100
//	0 <= rStart < rows
//	0 <= cStart < cols
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** spiralMatrixIII(int rows, int cols, int rStart, int cStart, int* returnSize, int** returnColumnSizes) {
    int **res = (int **)malloc(sizeof(int *) * (rows * cols));
    *returnColumnSizes = (int *)malloc(sizeof(int) * (rows * cols));
    int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, t = 0, p = 0, q = 0, r = 0, s = 0;
    int **dir = (int **)malloc(sizeof(int *) * 4);
    for (i = 0; i < 4; i++) {
        dir[i] = (int *)malloc(sizeof(int) * 2);
    }
    dir[0][0] = 0;
    dir[0][1] = 1;
    dir[1][0] = 1;
    dir[1][1] = 0;
    dir[2][0] = 0;
    dir[2][1] = -1;
    dir[3][0] = -1;
    dir[3][1] = 0;
    res[0] = (int *)malloc(sizeof(int) * 2);
    res[0][0] = rStart;
    res[0][1] = cStart;
    (*returnColumnSizes)[0] = 2;
    *returnSize = 1;
    for (i = 1; i < rows * cols; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < i / 2 + 1; k++) {
                r = rStart + dir[j][0] * k;
                s = cStart + dir[j][1] * k;
                if (r >= 0 && r < rows && s >= 0 && s < cols) {
                    res[*returnSize] = (int *)malloc(sizeof(int) * 2);
                    res[*returnSize][0] = r;
                    res[*returnSize][1] = s;
                    (*returnColumnSizes)[*returnSize] = 2;
                    (*returnSize)++;
                }
            }
        }
        rStart--;
        cStart--;
    }
    return res;    
}