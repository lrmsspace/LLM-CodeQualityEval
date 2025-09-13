/**https://leetcode.com/problems/rotting-oranges/ */
//You are given an m x n grid where each cell can have one of three values:
//	0 representing an empty cell,
//	1 representing a fresh orange, or
//	2 representing a rotten orange.
//Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
//Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
// 
//Example 1:
//Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
//Output: 4
//Example 2:
//Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
//Output: -1
//Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
//Example 3:
//Input: grid = [[0,2]]
//Output: 0
//Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 10
//	grid[i][j] is 0, 1, or 2.
class Solution {
    public int orangesRotting(int[][] grid) {
           int m = grid.length, n = grid[0].length;
            Queue<int[]> queue = new LinkedList<>();
            int freshCount = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 2) {
                        queue.offer(new int[]{i, j});
                    } else if (grid[i][j] == 1) {
                        freshCount++;
                    }
                }
            }
            if (freshCount == 0) return 0;
            
            int minutes = 0;
            int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            
            while (!queue.isEmpty()) {
                int size = queue.size();
                for (int i = 0; i < size; i++) {
                    int[] rottenOrange = queue.poll();
                    for (int[] direction : directions) {
                        int x = rottenOrange[0] + direction[0];
                        int y = rottenOrange[1] + direction[1];
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                            grid[x][y] = 2;
                            freshCount--;
                            queue.offer(new int[]{x, y});
                        }
                    }
                }
                minutes++;
            }
            
            return freshCount == 0 ? minutes - 1 : -1; // Return the minimum number of minutes until no cell has a fresh orange     
    }
}