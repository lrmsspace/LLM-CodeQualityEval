/**https://leetcode.com/problems/shortest-bridge/ */
//You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
//An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
//You may change 0's to 1's to connect the two islands to form one island.
//Return the smallest number of 0's you must flip to connect the two islands.
// 
//Example 1:
//Input: grid = [[0,1],[1,0]]
//Output: 1
//Example 2:
//Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
//Output: 2
//Example 3:
//Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
//Output: 1
// 
//Constraints:
//	n == grid.length == grid[i].length
//	2 <= n <= 100
//	grid[i][j] is either 0 or 1.
//	There are exactly two islands in grid.  
class Solution {
    public int shortestBridge(int[][] grid) 
    {
        int m = grid.length, n = grid[0].length;
        int[][] dirs = new int[][] { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        Queue<int[]> queue = new LinkedList<>();
        boolean[][] visited = new boolean[m][n];
        boolean found = false;
        for (int i = 0; i < m && !found; i++)
        {
            for (int j = 0; j < n && !found; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(grid, i, j, queue, visited, dirs);
                    found = true;
                }
            }
        }
        int step = 0;
        while (!queue.isEmpty())
        {
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                int[] cur = queue.poll();
                for (int[] dir : dirs)
                {
                    int x = cur[0] + dir[0];
                    int y = cur[1] + dir[1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y])
                    {
                        if (grid[x][y] == 1)
                        {
                            return step;
                        }
                        queue.offer(new int[] { x, y });
                        visited[x][y] = true;
                    }
                }
            }
            step++;
        }
        return -1;
    
    }
}