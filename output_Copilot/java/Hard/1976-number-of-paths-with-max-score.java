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
        int n = board.size(), m = board.get(0).length();
        int[][] dp = new int[n][m], count = new int[n][m];
        int mod = 1000000007;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (board.get(i).charAt(j) == 'X') continue;
                if (i == n - 1 && j == m - 1) {
                    dp[i][j] = 0;
                    count[i][j] = 1;
                } else {
                    int maxScore = 0, numPaths = 0;
                    for (int[] dir : new int[][]{{-1, 0}, {0, -1}, {-1, -1}}) {
                        int ni = i + dir[0], nj = j + dir[1];
                        if (ni >= 0 && nj >= 0 && board.get(ni).charAt(nj) != 'X') {
                            if (dp[ni][nj] > maxScore) {
                                maxScore = dp[ni][nj];
                                numPaths = count[ni][nj];
                            } else if (dp[ni][nj] == maxScore) {
                                numPaths += count[ni][nj];
                                numPaths %= mod;
                            }
                        }
                    }
                    dp[i][j] = maxScore + (board.get(i).charAt(j) == 'E' ? 0 : board.get(i).charAt(j) - '0');
                    count[i][j] = numPaths;
                }
            }
        }
        return dp[0][0] == 0 ? new int[]{0, 0} : new int[]{dp[0][0], count[0][0]};        
    }
}