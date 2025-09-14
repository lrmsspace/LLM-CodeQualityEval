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
    public int largestIsland(int[][] grid) {
            int n = grid.length;
            int[] size = new int[n * n + 1];
            int[] dx = new int[]{-1, 0, 1, 0};
            int[] dy = new int[]{0, 1, 0, -1};
            int ans = 0;
            int index = 2;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        int area = 0;
                        Queue<int[]> queue = new LinkedList<>();
                        queue.offer(new int[]{i, j});
                        grid[i][j] = index;
                        while (!queue.isEmpty()) {
                            int[] cur = queue.poll();
                            int x = cur[0], y = cur[1];
                            area++;
                            for (int[] dir : dirs) {
                                int nx = x + dir[0], ny = y + dir[1];
                                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                                    queue.offer(new int[]{nx, ny});
                                    grid[nx][ny] = index;
                                }
                            }
                        }
                    }
                }
            }
            return grid;
    }
}