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
class Solution {
    public boolean hasValidPath(int[][] grid) {
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        return dfs(grid, 0, 0, visited, directions);
    }

    private boolean dfs(int[][] grid, int i, int j, boolean[][] visited, int[][] directions) {
        if (i == grid.length - 1 && j == grid[0].length - 1) {
            return true;
        }
        visited[i][j] = true;
        int[][] nexts = getNexts(grid, i, j, directions);
        for (int[] next : nexts) {
            int x = next[0];
            int y = next[1];
            if (!visited[x][y]) {
                if (dfs(grid, x, y, visited, directions)) {
                    return true;
                }
            }
        }
        return false;
    }

    private int[][] getNexts(int[][] grid, int i, int j, int[][] directions) {
        int[][] nexts = new int[2][2];
        int k = 0;
        switch (grid[i][j]) {
            case 1:
                nexts[k++] = new int[]{i, j + 1};
                nexts[k++] = new int[]{i, j - 1};
                break;
            case 2:
                nexts[k++] = new int[]{i + 1, j};
                nexts[k++] = new int[]{i - 1, j};
                break;
            case 3:
                nexts[k++] = new int[]{i, j + 1};
                nexts[k++] = new int[]{i + 1, j};
                break;
            case 4:
                nexts[k++] = new int[]{i, j - 1};
                nexts[k++] = new int[]{i + 1, j};
                break;
            case 5:
                nexts[k++] = new int[]{i, j + 1};
                nexts[k++] = new int[]{i - 1, j};
                break;
            case 6:
                nexts[k++] = new int[]{i, j - 1};
                nexts[k++] = new int[]{i - 1, j};
                break;
        }
        return nexts;
    }
}