/**https://leetcode.com/problems/shortest-path-in-binary-matrix/ */
//Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
//A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
//	All the visited cells of the path are 0.
//	All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
//The length of a clear path is the number of visited cells of this path.
// 
//Example 1:
//Input: grid = [[0,1],[1,0]]
//Output: 2
//Example 2:
//Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
//Output: 4
//Example 3:
//Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
//Output: -1
// 
//Constraints:
//	n == grid.length
//	n == grid[i].length
//	1 <= n <= 100
//	grid[i][j] is 0 or 1
class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0, 1});
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int x = current[0], y = current[1], steps = current[2];
            if (x == n - 1 && y == n - 1) {
                return steps;
            }
            for (int[] dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                    queue.offer(new int[]{nx, ny, steps + 1});
                    grid[nx][ny] = 1; // Mark visited
                }
            }
        }
        return -1;
        
    }
}