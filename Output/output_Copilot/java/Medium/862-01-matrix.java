/**https://leetcode.com/problems/01-matrix/ */
//Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
//The distance between two adjacent cells is 1.
// 
//Example 1:
//Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
//Output: [[0,0,0],[0,1,0],[0,0,0]]
//Example 2:
//Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
//Output: [[0,0,0],[0,1,0],[1,2,1]]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 104
//	1 <= m * n <= 104
//	mat[i][j] is either 0 or 1.
//	There is at least one 0 in mat.
class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[][] dist = new int[m][n];
        boolean[][] visited = new boolean[m][n];
        Queue<int[]> queue = new LinkedList<>();

        // Initialize the queue with all the 0 cells and mark them as visited
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    queue.offer(new int[]{i, j});
                    visited[i][j] = true;
                } else {
                    dist[i][j] = Integer.MAX_VALUE; // Set initial distance to a large value
                }
            }
        }

        // Directions for moving up, down, left, right
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // BFS to find the nearest 0 for each cell
        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            for (int[] dir : directions) {
                int newRow = cell[0] + dir[0];
                int newCol = cell[1] + dir[1];
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visited[newRow][newCol]) {
                    dist[newRow][newCol] = dist[cell[0]][cell[1]] + 1;
                    visited[newRow][newCol] = true;
                    queue.offer(new int[]{newRow, newCol});
                }
            }
        }

        return dist;        
    }
}