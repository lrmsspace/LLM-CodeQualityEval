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
int** spiralMatrixIII(int rows, int cols, int rStart, int cStart, int* returnSize, int** returnColumnSizes){
    int **ans = malloc(sizeof(int*) * 1000);
    *returnColumnSizes = malloc(sizeof(int) * 1000);
    *returnSize = 0;
    int x = rStart, y = cStart;
    ans[(*returnSize)++] = malloc(sizeof(int) * 2);
    ans[*returnSize - 1][0] = x;    
    ans[*returnSize - 1][1] = y;
    ans[*returnSize - 1][1] = y;
    (*returnColumnSizes)[*returnSize - 1] = 2;
    while (*returnSize < rows * cols) {
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= i + 1; j++) {
                x += dx[i];
                y += dy[i];
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    ans[(*returnSize)++] = malloc(sizeof(int) * 2);
                   ans[*returnSize - 1][0] = x;
                }
            }
        }
    }
    return ans;
}