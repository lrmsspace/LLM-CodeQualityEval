/**https://leetcode.com/problems/matrix-cells-in-distance-order/ */
//You are given four integers row, cols, rCenter, and cCenter. There is a rows x cols matrix and you are on the cell with the coordinates (rCenter, cCenter).
//Return the coordinates of all cells in the matrix, sorted by their distance from (rCenter, cCenter) from the smallest distance to the largest distance. You may return the answer in any order that satisfies this condition.
//The distance between two cells (r1, c1) and (r2, c2) is |r1 - r2| + |c1 - c2|.
// 
//Example 1:
//Input: rows = 1, cols = 2, rCenter = 0, cCenter = 0
//Output: [[0,0],[0,1]]
//Explanation: The distances from (0, 0) to other cells are: [0,1]
//Example 2:
//Input: rows = 2, cols = 2, rCenter = 0, cCenter = 1
//Output: [[0,1],[0,0],[1,1],[1,0]]
//Explanation: The distances from (0, 1) to other cells are: [0,1,1,2]
//The answer [[0,1],[1,1],[0,0],[1,0]] would also be accepted as correct.
//Example 3:
//Input: rows = 2, cols = 3, rCenter = 1, cCenter = 2
//Output: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
//Explanation: The distances from (1, 2) to other cells are: [0,1,1,2,2,3]
//There are other answers that would also be accepted as correct, such as [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]].
// 
//Constraints:
//	1 <= rows, cols <= 100
//	0 <= rCenter < rows
//	0 <= cCenter < cols
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** allCellsDistOrder(int rows, int cols, int rCenter, int cCenter, int* returnSize, int** returnColumnSizes){
    int i, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z;
    int** ans = (int**)malloc(sizeof(int*) * rows * cols);
    int* ans_cols = (int*)malloc(sizeof(int) * rows * cols);
    int* ans_row = (int*)malloc(sizeof(int) * rows * cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            ans[i * cols + j] = (int*)malloc(sizeof(int) * 2);
            ans[i * cols + j][0] = i;
            ans[i * cols + j][1] = j;
            ans_cols[i * cols + j] =2;
        }
    }
    *returnSize = rows * cols;
    *returnColumnSizes = ans_cols;
    for (i = 0; i < rows * cols; i++) {
        for (j = i + 1; j < rows * cols; j++) {
            if (abs(ans[i][0] - rCenter) + abs(ans[i][1] - cCenter) > abs(ans[j][0] - rCenter) + abs(ans[j][1] - cCenter)) {
                int* temp = ans[i];
            }
        }
    }
    return ans;
}