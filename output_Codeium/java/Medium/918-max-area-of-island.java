/**https://leetcode.com/problems/max-area-of-island/ */
//You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
//The area of an island is the number of cells with a value 1 in the island.
//Return the maximum area of an island in grid. If there is no island, return 0.
// 
//Example 1:
//Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
//Output: 6
//Explanation: The answer is not 11, because the island must be connected 4-directionally.
//Example 2:
//Input: grid = [[0,0,0,0,0,0,0,0]]
//Output: 0
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 50
//	grid[i][j] is either 0 or 1.
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int maxArea = 0;
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    Stack<int[]> stack = new Stack<>();
                    stack.push(new int[]{i, j});
                    while (!stack.isEmpty()) {
                        int[] pos = stack.pop();
                        int x = pos[0];
                        int y = pos[1];
                        if (grid[x][y] == 1) {
                            area++;
                            grid[x][y] = 0;
                            for (int[] direction : directions) {
                                int nx = x + direction[0];
                                int ny = y + direction[1];
                                if (nx >= 0 && nx < grid.length && ny >= 0 && ny < grid[nx].length && grid[nx][ny] == 1) {
                                    stack.push(new int[]{nx, ny});
                                }
                            }
                        }
                    }
                    maxArea = Math.max(maxArea, area);
                }
            }
        }
        return maxArea;
        
    }
}