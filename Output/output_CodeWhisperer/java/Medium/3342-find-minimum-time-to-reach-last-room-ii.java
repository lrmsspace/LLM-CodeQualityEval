/*
import java.util.PriorityQueue;
import java.util.Arrays;
 There is a dungeon with n x m rooms arranged as a grid.
 You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes one second for one move and two seconds for the next, alternating between the two.
 Return the minimum time to reach the room (n - 1, m - 1).
 Two rooms are adjacent if they share a common wall, either horizontally or vertically.
 Example 1:
 Input: moveTime = [[0,4],[4,4]]
 Output: 7
 Explanation:
 The minimum time required is 7 seconds.
 At time t == 4, move from room (0, 0) to room (1, 0) in one second.
 At time t == 5, move from room (1, 0) to room (1, 1) in two seconds.
 Example 2:
 Input: moveTime = [[0,0,0,0],[0,0,0,0]]
 Output: 6
 Explanation:
 The minimum time required is 6 seconds.
 At time t == 0, move from room (0, 0) to room (1, 0) in one second.
 At time t == 1, move from room (1, 0) to room (1, 1) in two seconds.
 At time t == 3, move from room (1, 1) to room (1, 2) in one second.
 At time t == 4, move from room (1, 2) to room (1, 3) in two seconds.
 Example 3:
 Input: moveTime = [[0,1],[1,2]]
 Output: 4
 Constraints:
 2 <= n == moveTime.length <= 750
 2 <= m == moveTime[i].length <= 750
 0 <= moveTime[i][j] <= 109
*/

class Solution {
    public int minTimeToReach(int[][] moveTime) {
        int n = moveTime.length, m = moveTime[0].length;
        int[][] dp = new int[n][m];
        for (int[] row : dp) Arrays.fill(row, Integer.MAX_VALUE);
        dp[0][0] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[2] - b[2]);
        pq.offer(new int[]{0, 0, 0});
        int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int x = cur[0], y = cur[1], t = cur[2];
            if (x == n - 1 && y == m - 1) return t;
            for (int[] dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                int nt = Math.max(t, moveTime[x][y]);
                if (nt + 1 < dp[nx][ny]) {
                    dp[nx][ny] = nt + 1;
                    pq.offer(new int[]{nx, ny, nt + 1});
                }
            }
        }
        return dp[n - 1][m - 1];        
    }
}