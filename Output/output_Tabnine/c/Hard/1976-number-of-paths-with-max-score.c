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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pathsWithMaxScore(char ** board, int boardSize, int* returnSize){
    int m = boardSize, n = boardSize;
    int MOD = 1e9 + 7;
    int dp[m][n];
    int dp_prev[m][n];
    memset(dp, 0, sizeof(dp));
    memset(dp_prev, 0, sizeof(dp_prev));
    int max_sum = 0, max_paths = 0;
    
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (board[i][j] == 'E') {
                dp[i][j] = 0;
            } else if (board[i][j] == 'X') {
                dp[i][j] = 0;
            } else if (board[i][j] == 'S') {
                dp[i][j] = board[i][j] - '0';
                max_sum = max(max_sum, dp[i][j]);
            } else {
                int num = board[i][j] - '0';
                dp[i][j] = num + max(dp[i + 1][j], dp[i][j + 1]);
                if (i + 1 < m && j + 1 < n && board[i + 1][j + 1]!= 'X') {
                    dp[i][j] = (dp[i][j] + dp_prev[i + 1][j + 1]) % MOD;
                }
                max_sum = max(max_sum, dp[i][j]);
            }
            if (i + 1 < m && j + 1 < n && board[i + 1][j + 1]!= 'X') {
                dp_prev[i][j] = dp[i + 1][j + 1];
            }
        }
    }
    
    *returnSize = 2;
    int *result = malloc(sizeof(int) * 2);
    result[0] = max_sum;
    result[1] = dp[0][0];
    return result;
}
