/*
 You are given a 2D character grid matrix of size m x n, represented as an array of strings, where matrix[i][j] represents the cell at the intersection of the ith row and jth column. Each cell is one of the following:
 '.' representing an empty cell.
 '#' representing an obstacle.
 An uppercase letter ('A'-'Z') representing a teleportation portal.
 You start at the top-left cell (0, 0), and your goal is to reach the bottom-right cell (m - 1, n - 1). You can move from the current cell to any adjacent cell (up, down, left, right) as long as the destination cell is within the grid bounds and is not an obstacle.
 If you step on a cell containing a portal letter and you haven't used that portal letter before, you may instantly teleport to any other cell in the grid with the same letter. This teleportation does not count as a move, but each portal letter can be used at most once during your journey.
 Return the minimum number of moves required to reach the bottom-right cell. If it is not possible to reach the destination, return -1.
 Example 1:
 Input: matrix = ["A..",".A.","..."]
 Output: 2
 Explanation:
 Before the first move, teleport from (0, 0) to (1, 1).
 In the first move, move from (1, 1) to (1, 2).
 In the second move, move from (1, 2) to (2, 2).
 Example 2:
 Input: matrix = [".#...",".#.#.",".#.#.","...#."]
 Output: 13
 Explanation:
 Constraints:
 1 <= m == matrix.length <= 103
 1 <= n == matrix[i].length <= 103
 matrix[i][j] is either '#', '.', or an uppercase English letter.
 matrix[0][0] is not an obstacle.
*/

class Solution {
    public int minMoves(String[] matrix) {
        int m = matrix.length;
        int n = matrix[0].length();
        int[][] dp = new int[m][n]; 
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0][0] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {   
                if (matrix[i][j] == '#') continue;
                if (i > 0) dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + 1);
                if (j > 0) dp[i][j] = Math.min(dp[i][j], dp[i][j - 1] + 1);
                if (matrix[i][j]!= '.') {
                    int x = i, y = j;
                    while (x < m && y < n && matrix[x][y]!= '.') {
                        dp[x][y] = Math.min(dp[x][y], dp[i][j] + Math.abs(x - i) + Math.abs(y - j));
                        x++;
                        y++;
                    }
                }
            }
            dp[i][n - 1] = Math.min(dp[i][n - 1], dp[i][n - 2] + 1);    
            dp[m - 1][i] = Math.min(dp[m - 1][i], dp[m - 2][i] + 1);    
            if (matrix[m - 1][i]!= '.') {
                int x = m - 1, y = i;
                while (x >= 0 && y >= 0 && matrix[x][y]!= '.') {
                    dp[x][y] = Math.min(dp[x][y], dp[m - 1][i] + Math.abs(x - (m - 1)) + Math.abs(y - i));
                    x--;
                    y--;
                }
            }
            dp[m - 1][n - 1] = Math.min(dp[m - 1][n - 1], dp[m - 2][n - 1] + 1);    

            for (int j = 0; j < n; j++) {
                if (matrix[m - 1][j]!= '.') {
                    int x = m - 1, y = j;
                    while (x >= 0 && y >= 0 && matrix[x][y]!= '.') {
                        dp[x][y] = Math.min(dp[x][y], dp[m - 1][j] + Math.abs(x - (m - 1)) + Math.abs(y - j));
                        x--;
                        y--;
                    }
                }
            }
        }
        return dp[m - 1][n - 1] == Integer.MAX_VALUE? -1 : dp[m - 1][n - 1];
        
    }
}