/**https://leetcode.com/problems/path-with-minimum-effort/ */
//You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
//A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
//Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
// 
//Example 1:
//Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
//Output: 2
//Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
//This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
//Example 2:
//Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
//Output: 1
//Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
//Example 3:
//Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
//Output: 0
//Explanation: This route does not require any effort.
// 
//Constraints:
//	rows == heights.length
//	columns == heights[i].length
//	1 <= rows, columns <= 100
//	1 <= heights[i][j] <= 106
class Solution {
    public int minimumEffortPath(int[][] heights) {
        int n = heights.length;
        int m = heights[0].length;
        int[][] dirs = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int left = 0, right = 1000000;
        while (left < right) {
            int mid = left + (right - left) / 2;
            Queue<int[]> q = new LinkedList<>();
            q.add(new int[]{0, 0});
            boolean[] visited = new boolean[n * m];
            visited[0] = true;
            while (!q.isEmpty()) {
                int[] cur = q.poll();
                int x = cur[0], y = cur[1];
                for (int[] dir : dirs) {
                    int nx = x + dir[0], ny = y + dir[1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx * m + ny] && Math.abs(heights[x][y] - heights[nx][ny]) <= mid) {
                        q.add(new int[]{nx, ny});
                        visited[nx * m + ny] = true;
                    }
                }
            }
            if (visited[n * m - 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;        
    }
}