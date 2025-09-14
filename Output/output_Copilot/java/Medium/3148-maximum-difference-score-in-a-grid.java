/*
 You are given an m x n matrix grid consisting of positive integers. You can move from a cell in the matrix to any other cell that is either to the bottom or to the right (not necessarily adjacent). The score of a move from a cell with the value c1 to a cell with the value c2 is c2 - c1.
 You can start at any cell, and you have to make at least one move.
 Return the maximum total score you can achieve.
 Example 1:
 Input: grid = [[9,5,7,3],[8,9,6,1],[6,7,14,3],[2,5,3,1]]
 Output: 9
 Explanation: We start at the cell (0, 1), and we perform the following moves:
 - Move from the cell (0, 1) to (2, 1) with a score of 7 - 5 = 2.
 - Move from the cell (2, 1) to (2, 2) with a score of 14 - 7 = 7.
 The total score is 2 + 7 = 9.
 Example 2:
 Input: grid = [[4,3,2],[3,2,1]]
 Output: -1
 Explanation: We start at the cell (0, 0), and we perform one move: (0, 0) to (0, 1). The score is 3 - 4 = -1.
 Constraints:
 m == grid.length
 n == grid[i].length
 2 <= m, n <= 1000
 4 <= m * n <= 105
 1 <= grid[i][j] <= 105
*/

class Solution {
    public int maxScore(List<List<Integer>> grid) {
        int m = grid.size();
        int n = grid.get(0).size();
        int[][] dp = new int[m][n];
        
        // Initialize the first cell
        dp[0][0] = 0;
        
        // Fill the first row
        for (int j = 1; j < n; j++) {
            dp[0][j] = grid.get(0).get(j) - grid.get(0).get(j - 1);
        }
        
        // Fill the first column
        for (int i = 1; i < m; i++) {
            dp[i][0] = grid.get(i).get(0) - grid.get(i - 1).get(0);
        }
        
        // Fill the rest of the dp array
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int scoreFromTop = dp[i - 1][j] + (grid.get(i).get(j) - grid.get(i - 1).get(j));
                int scoreFromLeft = dp[i][j - 1] + (grid.get(i).get(j) - grid.get(i).get(j - 1));
                dp[i][j] = Math.max(scoreFromTop, scoreFromLeft);
            }
        }
        
        // Find the maximum score in the last row and last column
        int maxScore = Integer.MIN_VALUE;
        for (int i = 0; i < m; i++) {
            maxScore = Math.max(maxScore, dp[i][n - 1]);
        }
        for (int j = 0; j < n; j++) {
            maxScore = Math.max(maxScore, dp[m - 1][j]);
        }
        
        return maxScore;        
    }
}