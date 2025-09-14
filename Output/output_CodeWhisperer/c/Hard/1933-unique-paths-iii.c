/**https://leetcode.com/problems/unique-paths-iii/ */
//You are given an m x n integer array grid where grid[i][j] could be:
//	1 representing the starting square. There is exactly one starting square.
//	2 representing the ending square. There is exactly one ending square.
//	0 representing empty squares we can walk over.
//	-1 representing obstacles that we cannot walk over.
//Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.
// 
//Example 1:
//Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
//Output: 2
//Explanation: We have the following two paths: 
//1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
//2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
//Example 2:
//Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
//Output: 4
//Explanation: We have the following four paths: 
//1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
//2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
//3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
//4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
//Example 3:
//Input: grid = [[0,1],[2,0]]
//Output: 0
//Explanation: There is no path that walks over every empty square exactly once.
//Note that the starting and ending square can be anywhere in the grid.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 20
//	1 <= m * n <= 20
//	-1 <= grid[i][j] <= 2
//	There is exactly one starting cell and one ending cell.
int uniquePathsIII(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];

    int start_x = -1, start_y = -1, end_x = -1, end_y = -1;

    int empty_squares = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                start_x = i;
                start_y = j;
            } else if (grid[i][j] == 2) {
                end_x = i;
                end_y = j;
            } else if (grid[i][j] == 0) {
                empty_squares++;
            }
        }
    }

    int paths = 0;

    int dfs(int x, int y, int remaining_squares) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == -1) {
            return 0;
        }

        if (x == end_x && y == end_y) {
            if (remaining_squares == 0) {
                return 1;
            } else {
                return 0;
            }
        }

        int original_value = grid[x][y];
        grid[x][y] = -1;

        int path_count = 0;

        path_count += dfs(x + 1, y, remaining_squares - 1);
        path_count += dfs(x - 1, y, remaining_squares - 1);
        path_count += dfs(x, y + 1, remaining_squares - 1);
        path_count += dfs(x, y - 1, remaining_squares - 1);

        grid[x][y] = original_value;

        return path_count;
    };
    return dfs(start_x, start_y, empty_squares + 1);    
    
}