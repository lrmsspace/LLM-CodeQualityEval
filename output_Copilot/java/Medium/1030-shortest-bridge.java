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
    public int shortestBridge(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        boolean[][] visited = new boolean[n][m];
        Queue<int[]> queue = new LinkedList<>();
        boolean found = false;

        // Find the first island and mark it as visited
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    dfs(grid, visited, queue, i, j);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        // BFS to find the shortest path to the second island
        int steps = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] cell = queue.poll();
                for (int[] dir : new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
                    int x = cell[0] + dir[0], y = cell[1] + dir[1];
                    if (x >= 0 && x < n && y >= 0 && y < m) {
                        if (grid[x][y] == 1) return steps; // Found the second island
                        if (grid[x][y] == 0 && !visited[x][y]) {
                            visited[x][y] = true;
                            queue.offer(new int[]{x, y});
                        }
                    }
                }
            }
            steps++;
        }

        return -1; // Should never reach here since there are exactly two islands    
    }
}