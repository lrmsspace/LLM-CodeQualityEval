/**https://leetcode.com/problems/map-of-highest-peak/ */
//You are given an integer matrix isWater of size m x n that represents a map of land and water cells.
//	If isWater[i][j] == 0, cell (i, j) is a land cell.
//	If isWater[i][j] == 1, cell (i, j) is a water cell.
//You must assign each cell a height in a way that follows these rules:
//	The height of each cell must be non-negative.
//	If the cell is a water cell, its height must be 0.
//	Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
//Find an assignment of heights such that the maximum height in the matrix is maximized.
//Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.
// 
//Example 1:
//Input: isWater = [[0,1],[0,0]]
//Output: [[1,0],[2,1]]
//Explanation: The image shows the assigned heights of each cell.
//The blue cell is the water cell, and the green cells are the land cells.
//Example 2:
//Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
//Output: [[1,1,0],[0,1,1],[1,2,2]]
//Explanation: A height of 2 is the maximum possible height of any assignment.
//Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.
// 
//Constraints:
//	m == isWater.length
//	n == isWater[i].length
//	1 <= m, n <= 1000
//	isWater[i][j] is 0 or 1.
//	There is at least one water cell.
class Solution {
    public int[][] highestPeak(int[][] isWater) {
        int m = isWater.length, n = isWater[0].length;
        int[][] height = new int[m][n];
        Queue<int[]> queue = new LinkedList<>();

        // Initialize the queue with water cells and set their height to 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    queue.offer(new int[]{i, j});
                } else {
                    height[i][j] = -1; // Mark land cells as unvisited
                }
            }
        }

        // Directions for adjacent cells (up, down, left, right)
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // BFS to assign heights to land cells
        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            int x = cell[0], y = cell[1];

            for (int[] dir : directions) {
                int newX = x + dir[0], newY = y + dir[1];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && height[newX][newY] == -1) {
                    height[newX][newY] = height[x][y] + 1;
                    queue.offer(new int[]{newX, newY});
                }
            }
        }

        return height; // Return the matrix with assigned heights   
    }
}