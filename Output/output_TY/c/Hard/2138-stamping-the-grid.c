/**https://leetcode.com/problems/stamping-the-grid/ */
//You are given an m x n binary matrix grid where each cell is either 0 (empty) or 1 (occupied).
//You are then given stamps of size stampHeight x stampWidth. We want to fit the stamps such that they follow the given restrictions and requirements:
//	Cover all the empty cells.
//	Do not cover any of the occupied cells.
//	We can put as many stamps as we want.
//	Stamps can overlap with each other.
//	Stamps are not allowed to be rotated.
//	Stamps must stay completely inside the grid.
//Return true if it is possible to fit the stamps while following the given restrictions and requirements. Otherwise, return false.
// 
//Example 1:
//Input: grid = [[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0]], stampHeight = 4, stampWidth = 3
//Output: true
//Explanation: We have two overlapping stamps (labeled 1 and 2 in the image) that are able to cover all the empty cells.
//Example 2:
//Input: grid = [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]], stampHeight = 2, stampWidth = 2 
//Output: false 
//Explanation: There is no way to fit the stamps onto all the empty cells without the stamps going outside the grid.
// 
//Constraints:
//	m == grid.length
//	n == grid[r].length
//	1 <= m, n <= 105
//	1 <= m * n <= 2 * 105
//	grid[r][c] is either 0 or 1.
//	1 <= stampHeight, stampWidth <= 105
bool possibleToStamp(int** grid, int gridSize, int* gridColSize, int stampHeight, int stampWidth){
    int m = gridSize, n = *gridColSize;
    int *row = malloc(sizeof(int) * n);
    int *col = malloc(sizeof(int) * m);
    memset(row, 0, sizeof(int) * n);
    memset(col, 0, sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                row[j]++;
                col[i]++;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                if (i + stampHeight > m || j + stampWidth > n) {
                    return false;
                }
                if (row[j] >= stampWidth && col[i] >= stampHeight) {
                    for (int k = i; k < i + stampHeight; k++) {
                        for (int l = j; l < j + stampWidth; l++) {
                            row[l]--;
                            col[k]--;
                        }
                    }   
                }
            }
        }
    }
    return true;
}