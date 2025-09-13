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
    int m = gridSize, n = *gridColSize;
    int dirs[5] = {0, 1, 0, -1, 0};
    int total = m * n;
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            count += grid[i][j];
        }
    }
    if (count == total) {
        return false;
    }
    int** visited = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        visited[i] = (int*)malloc(sizeof(int) * n);
        memset(visited[i], 0, sizeof(int) * n);
    }
    int** stamp = (int**)malloc(sizeof(int*) * stampHeight);
    for (int i = 0; i < stampHeight; i++) {
        stamp[i] = (int*)malloc(sizeof(int) * stampWidth);
    }
    int** visited2 = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        visited2[i] = (int*)malloc(sizeof(int) * n);
        memset(visited2[i], 0, sizeof(int) * n);
    }
    int** stamp2 = (int**)malloc(sizeof(int*) * stampHeight);
    for (int i = 0; i < stampHeight; i++) {
        stamp2[i] = (int*)malloc(sizeof(int) * stampWidth);
    }
    while (count < total) {
        bool found = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0 && grid[i][j] == 0) {
                    bool valid = true;
                    for (int k = 0; k < stampHeight; k++) {
                        for (int l = 0; l < stampWidth; l++) {
                            if (i + k >= m || j + l >= n || grid[i + k][j + l] == 1) {
                                valid = false;
                                break;
                            }
                            stamp[k][l] = grid[i + k][j + l];
                        }
                        if (!valid) {
                            break;
                        }
                    }
                    if (valid) {
                        found = true;
                        for (int k = 0; k < stampHeight; k++) {
                            for (int l = 0; l < stampWidth; l++) {
                                visited[i + k][j + l] = 1;
                            }
                        }
                        count += stampHeight * stampWidth;
                    }
                }
                if (found) {
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        if (!found) {
            for (int i = 0; i < m; i++) {
                free(visited[i]);
                free(visited2[i]);
            }
            for (int i = 0; i < stampHeight; i++) {
                free(stamp[i]);
                free(stamp2[i]);
            }
            free(visited);
            free(visited2);
            free(stamp);
            free(stamp2);
            return false;
        }
    }
    for (int i = 0; i < m; i++) {
        free(visited[i]);
        free(visited2[i]);
    }
    for (int i = 0; i < stampHeight; i++) {
        free(stamp[i]);
        free(stamp2[i]);
    }
    free(visited);
    free(visited2);
    free(stamp);
    free(stamp2);
    return true;    
}