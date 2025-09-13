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
        int rows = board.size(), cols = board.get(0).length();
        int[][] dp = new int[rows][cols];
        int[][] cnt = new int[rows][cols];
        dp[rows - 1][cols - 1] = 0;
        cnt[rows - 1][cols - 1] = 1;
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                if (board.get(i).charAt(j) != 'X') {
                    int cur = board.get(i).charAt(j) - '0';
                    if (i < rows - 1 && dp[i + 1][j] != -1 && dp[i + 1][j] + cur > dp[i][j]) {
                        dp[i][j] = dp[i + 1][j] + cur;
                        cnt[i][j] = cnt[i + 1][j];
                    }
                    if (j < cols - 1 && dp[i][j + 1] != -1 && dp[i][j + 1] + cur > dp[i][j]) {
                        dp[i][j] = dp[i][j + 1] + cur;
                        cnt[i][j] = cnt[i][j + 1];
                    }
                    if (i < rows - 1 && j < cols - 1 && dp[i + 1][j + 1] != -1 && dp[i + 1][j + 1] + cur > dp[i][j]) {
                        dp[i][j] = dp[i + 1][j + 1] + cur;
                        cnt[i][j] = cnt[i + 1][j + 1];
                    }
                }
            }
        }
        return dp[0][0] == -1 ? new int[] { 0, 0 } : new int[] { dp[0][0], cnt[0][0] };
    }
}   