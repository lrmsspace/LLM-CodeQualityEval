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
class Solution {
    public int largestIsland(int[][] grid) 
    {
        int n = grid.length;
        int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int[] area = new int[n * n + 2];
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int index = i * n + j + 1;
                    area[index] = dfs(grid, i, j, index, dirs);
                    ans = Math.max(ans, area[index]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    int index = 1;
                    Set<Integer> seen = new HashSet<>();
                    for (int[] dir : dirs)
                    {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 1)
                        {
                            index += area[grid[x][y]];
                            seen.add(grid[x][y]);
                        }
                    }
                    ans = Math.max(ans, index);
                }
            }
        }
        return ans;
    
    }
}