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
bool possibleToStamp(int** grid, int gridSize, int* gridColSize, int stampHeight, int stampWidth) {
    int m = gridSize;
    int n = gridColSize[0];

    // Create an auxiliary matrix to keep track of the stamped regions
    int** stampable = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; ++i) {
        stampable[i] = (int*)calloc(n, sizeof(int));
    }

    // Fill the stampable matrix with the stamp dimensions
    for (int i = m - stampHeight; i >= 0; --i) {
        for (int j = n - stampWidth; j >= 0; --j) {
            bool canStamp = true;
            for (int x = 0; x < stampHeight && canStamp; ++x) {
                for (int y = 0; y < stampWidth && canStamp; ++y) {
                    if (grid[i + x][j + y] == 1) {
                        canStamp = false;
                    }
                }
            }
            if (canStamp) {
                for (int x = 0; x < stampHeight; ++x) {
                    for (int y = 0; y < stampWidth; ++y) {
                        stampable[i + x][j + y] = 1;
                    }
                }
            }
        }
    }

    // Check if all empty cells in the grid have been stamped
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 0 && stampable[i][j] == 0) {
                // Clean up memory
                for (int k = 0; k < m; ++k) {
                    free(stampable[k]);
                }
                free(stampable);
                return false;
            }
        }
    }

    // Clean up memory
    for (int i = 0; i < m; ++i) {
        free(stampable[i]);
    }
    free(stampable);
    return true;
}

