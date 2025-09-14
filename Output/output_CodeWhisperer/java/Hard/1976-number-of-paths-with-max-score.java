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
        int n = board.size(), m = board[0].length();
        int[][] dp = new int[n][m], cnt = new int[n][m];
        int[] mod = new int[]{(int)1e9 + 7};
        cnt[n - 1][m - 1] = 1;
        dp[n - 1][m - 1] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (board.get(i).charAt(j) == 'X') continue;
                for (int[] d : new int[][]{{0, -1}, {-1, 0}, {-1, -1}}) {
                    int x = i + d[0], y = j + d[1];
                    if (x < 0 || y < 0 || cnt[x][y] == 0) continue;
                    int val = dp[x][y] + (i == 0 && j == 0 ? 0 : board.get(i).charAt(j) - '0');
                    if (val > dp[i][j]) {
                        dp[i][j] = val;
                        cnt[i][j] = cnt[x][y];
                    } else if (val == dp[i][j]) {
                        cnt[i][j] = (cnt[i][j] + cnt[x][y]) % mod[0];
                    }
                }
            }
        }
        return new int[]{dp[0][0], cnt[0][0]};      
    }
}