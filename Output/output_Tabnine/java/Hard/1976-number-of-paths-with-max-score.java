/**https://leetcode.com/problems/number-of-paths-with-max-score/ */
//You are given a square board of characters. You can move on the board starting at the bottom right square marked with the character 'S'.
//You need to reach the top left square marked with the character 'E'. The rest of the squares are labeled either with a numeric character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there.
//Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, taken modulo 10^9 + 7.
//In case there is no path, return [0, 0].
// 
//Example 1:
//Input: board = ["E23","2X2","12S"]
//Output: [7,1]
//Example 2:
//Input: board = ["E12","1X1","21S"]
//Output: [4,2]
//Example 3:
//Input: board = ["E11","XXX","11S"]
//Output: [0,0]
// 
//Constraints:
//	2 <= board.length == board[i].length <= 100
class Solution {
    public int[] pathsWithMaxScore(List<String> board) {
        int m = board.size();
        int n = board[0].length();
        int[][] dp = new int[m][n];
        int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        dp[m - 1][n - 1] = board[m - 1][n - 1].equals("S")? 1 : 0;
        
        for (int i = m - 2; i >= 0; i--) {
            if (board[i][n - 1].equals("X")) continue;
            dp[i][n - 1] = dp[i + 1][n - 1] + (board[i][n - 1].matches("\\d")? Integer.parseInt(board[i][n - 1]) : 0);
        }
        
        for (int j = n - 2; j >= 0; j--) {
            if (board[m - 1][j].equals("X")) continue;
            dp[m - 1][j] = dp[m - 1][j + 1] + (board[m - 1][j].matches("\\d")? Integer.parseInt(board[m - 1][j]) : 0);
        }
        
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (board[i][j].equals("X")) continue;
                int maxSum = 0;
                for (int[] dir : dirs) {
                    int x = i + dir[0];
                    int y = j + dir[1];
                    if (x >= 0 && x < m && y >= 0 && y < n &&!board[x][y].equals("X")) {
                        maxSum = Math.max(maxSum, dp[x][y]);
                    }
                }
                dp[i][j] = maxSum + (board[i][j].matches("\\d")? Integer.parseInt(board[i][j]) : 0);
            }
        }
        
        int maxScore = 0;
        int count = 0;
        if (!board[0][0].equals("X")) {
            maxScore = dp[0][0];
            count = 1;
        }
        
        return new int[]{maxScore, count % (int)(1e9 + 7)};
    }
}