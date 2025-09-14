/**https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/ */
//You are given an m x n integer matrix grid and an array queries of size k.
//Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:
//	If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
//	Otherwise, you do not get any points, and you end this process.
//After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.
//Return the resulting array answer.
// 
//Example 1:
//Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
//Output: [5,8,1]
//Explanation: The diagrams above show which cells we visit to get points for each query.
//Example 2:
//Input: grid = [[5,2,1],[1,1,2]], queries = [3]
//Output: [0]
//Explanation: We can not get any points because the value of the top left cell is already greater than or equal to 3.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	2 <= m, n <= 1000
//	4 <= m * n <= 105
//	k == queries.length
//	1 <= k <= 104
//	1 <= grid[i][j], queries[i] <= 106
class Solution {
    public int[] maxPoints(int[][] grid, int[] queries) {
        int m = grid.length, n = grid[0].length;
        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, 1, 0, -1};
        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int q = queries[i], cnt = 0;
            boolean[][] vis = new boolean[m][n];
            Queue<int[]> que = new LinkedList<>();
            que.add(new int[]{0, 0});
            vis[0][0] = true;
            while (!que.isEmpty()) {
                int[] cur = que.poll();
                if (grid[cur[0]][cur[1]] >= q) break;
                cnt++;
                for (int j = 0; j < 4; j++) {
                    int nx = cur[0] + dx[j], ny = cur[1] + dy[j];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] && grid[nx][ny] < q) {
                        que.add(new int[]{nx, ny});
                        vis[nx][ny] = true;
                    }
                }
            }
            ans[i] = cnt;
        }
        return ans;
    }
}