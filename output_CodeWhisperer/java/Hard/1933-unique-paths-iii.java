/**https://leetcode.com/problems/unique-paths-iii/ */
//You are given an m x n integer array grid where grid[i][j] could be:
//	1 representing the starting square. There is exactly one starting square.
//	2 representing the ending square. There is exactly one ending square.
//	0 representing empty squares we can walk over.
//	-1 representing obstacles that we cannot walk over.
//Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.
// 
//Example 1:
//Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
//Output: 2
//Explanation: We have the following two paths: 
//1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
//2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
//Example 2:
//Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
//Output: 4
//Explanation: We have the following four paths: 
//1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
//2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
//3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
//4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
//Example 3:
//Input: grid = [[0,1],[2,0]]
//Output: 0
//Explanation: There is no path that walks over every empty square exactly once.
//Note that the starting and ending square can be anywhere in the grid.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 20
//	1 <= m * n <= 20
//	-1 <= grid[i][j] <= 2
//	There is exactly one starting cell and one ending cell.
import java.util.Arrays;
class Solution {
    public int uniquePathsIII(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int start = 0;
        int end = 0;
        int empty = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    start = i * n + j;
                } else if (grid[i][j] == 2) {
                    end = i * n + j;
                } else if (grid[i][j] == 0) {
                    empty++;
                }
            }
        }
        int[] dp = new int[1 << (m * n)];
        Arrays.fill(dp, -1);
        dp[1 << start] = 1;
        int[] dirs = {0, -1, 0, 1, 0};
        for (int state = 1; state < 1 << (m * n); state++) {
            if (dp[state] == -1) {
                continue;
            }
            int x = 0;
            int y = 0;
            for (int i = 0; i < m * n; i++) {
                if ((state >> i & 1) == 1) {
                    x = i / n;
                    y = i % n;
                }
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i];
                int ny = y + dirs[i + 1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }
                if (grid[nx][ny] == -1) {
                    continue;
                }
                if ((state >> (nx * n + ny) & 1) == 1) {
                    continue;
                }
                int nstate = state | (1 << (nx * n + ny));
                if (dp[nstate] == -1) {
                    dp[nstate] = 0;
                }
                dp[nstate] += dp[state];
            }
        }
        return dp[1 << end] == -1 ? 0 : dp[1 << end] * (empty == 0 ? 1 : 0);
    }
}