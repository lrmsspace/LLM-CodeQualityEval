/**https://leetcode.com/problems/making-a-large-island/ */
//You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
//Return the size of the largest island in grid after applying this operation.
//An island is a 4-directionally connected group of 1s.
// 
//Example 1:
//Input: grid = [[1,0],[0,1]]
//Output: 3
//Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
//Example 2:
//Input: grid = [[1,1],[1,0]]
//Output: 4
//Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
//Example 3:
//Input: grid = [[1,1],[1,1]]
//Output: 4
//Explanation: Can't change any 0 to 1, only one island with area = 4.
// 
//Constraints:
//	n == grid.length
//	n == grid[i].length
//	1 <= n <= 500
//	grid[i][j] is either 0 or 1.
int largestIsland(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int* parent = (int*)malloc(m * n * sizeof(int));
    int* size = (int*)malloc(m * n * sizeof(int));
    int* top = (int*)malloc(m * n * sizeof(int));
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int** copy = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        copy[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            copy[i][j] = grid[i][j];
        }
    }
    *returnSize = hitsSize;
    for (int i = 0; i < m * n; i++) {
        parent[i] = i;
        size[i] = 1;
        top[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (copy[0][i] == 1) {
            top[i] = 0;
            unionSet(parent, size, top, 0, i);
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (copy[i][j] == 1) {
                if (copy[i - 1][j] == 1) {
                    unionSet(parent, size, top, i * n + j, (i - 1) * n + j);
                }
                if (j > 0 && copy[i][j - 1] == 1) {
                    unionSet(parent, size, top, i * n + j, i * n + j - 1);
                }
            }
        }
    }
    for (int i = hitsSize - 1; i >= 0; i--) {
        int x = hits[i][0], y = hits[i][1];
        if (grid[x][y] == 0) {
            result[i] = 0;
            continue;
        }
        int prevTop = size[find(parent, 0)];
        copy[x][y] = 1;
        for (int d = 0; d < 4; d++) {   
            int nx = x + directions[d][0];
            int ny = y + directions[d][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && copy[nx][ny] == 1) {
            unionSet(parent, size, top, x * n + y, nx * n + ny);
            }
        }
        int newTop = size[find(parent, 0)];
        result[i] = newTop - prevTop;
        }
        free(parent);
        free(size);
        free(top);
        for (int i = 0; i < m; i++) {
        free(copy[i]);
        }
        free(copy);
        return result;
}