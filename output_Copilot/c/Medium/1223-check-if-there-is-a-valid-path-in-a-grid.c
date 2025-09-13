/**https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/ */
//You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:
//	1 which means a street connecting the left cell and the right cell.
//	2 which means a street connecting the upper cell and the lower cell.
//	3 which means a street connecting the left cell and the lower cell.
//	4 which means a street connecting the right cell and the lower cell.
//	5 which means a street connecting the left cell and the upper cell.
//	6 which means a street connecting the right cell and the upper cell.
//You will initially start at the street of the upper-left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.
//Notice that you are not allowed to change any street.
//Return true if there is a valid path in the grid or false otherwise.
// 
//Example 1:
//Input: grid = [[2,4,3],[6,5,2]]
//Output: true
//Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).
//Example 2:
//Input: grid = [[1,2,1],[1,2,1]]
//Output: false
//Explanation: As shown you the street at cell (0, 0) is not connected with any street of any other cell and you will get stuck at cell (0, 0)
//Example 3:
//Input: grid = [[1,1,2]]
//Output: false
//Explanation: You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 300
//	1 <= grid[i][j] <= 6
bool hasValidPath(int** grid, int gridSize, int* gridColSize) {
    int directions[7][4] = {
        {0, 0, 0, 0}, // Placeholder for 0-index (not used)
        {0, -1, 0, 1}, // Street type 1: left, right
        {-1, 0, 1, 0}, // Street type 2: up, down
        {0, -1, 1, 0}, // Street type 3: left, down
        {0, 1, 1, 0},  // Street type 4: right, down    
        {0, -1, -1, 0}, // Street type 5: left, up
        {0, 1, -1, 0}   // Street type 6: right, up
    };

    bool isValid(int x, int y, int prevX, int prevY, int** grid, int gridSize, int* gridColSize) {
        if (x < 0 || y < 0 || x >= gridSize || y >= gridColSize[x]) return false;
        int type = grid[x][y];
        for (int i = 0; i < 4; i += 2) {
            int nx = x + directions[type][i];
            int ny = y + directions[type][i + 1];
            if (nx == prevX && ny == prevY) return true;
        }
        return false;
    }

    bool dfs(int x, int y, int prevX, int prevY, int** grid, int gridSize, int* gridColSize, bool** visited) {
        if (x == gridSize - 1 && y == gridColSize[x] - 1) return true;
        visited[x][y] = true;

        int type = grid[x][y];
        for (int i = 0; i < 4; i += 2) {
            int nx = x + directions[type][i];
            int ny = y + directions[type][i + 1];
            if (nx >= 0 && ny >= 0 && nx < gridSize && ny < gridColSize[nx] && !visited[nx][ny] && isValid(nx, ny, x, y, grid, gridSize, gridColSize)) {
                if (dfs(nx, ny, x, y, grid, gridSize, gridColSize, visited)) return true;
            }
        }

        return false;
    }

    bool** visited = (bool**)malloc(gridSize * sizeof(bool*));
    for (int i = 0; i < gridSize; i++) {
        visited[i] = (bool*)calloc(gridColSize[i], sizeof(bool));
    }

    bool result = dfs(0, 0, -1, -1, grid, gridSize, gridColSize, visited);

    for (int i = 0; i < gridSize; i++) {
        free(visited[i]);
    }
    free(visited);

    return result;
}