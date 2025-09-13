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
    int maxSum = 0;
    int count = 0;
    int dp[101][101] = {0};
    int dir[3][2] = {{-1, -1}, {-1, 0}, {0, -1}};

    dp[boardSize-1][boardSize-1] = board[boardSize-1][boardSize-1] - '0';

    for (int i = boardSize-1; i >= 0; --i) {
        for (int j = boardSize-1; j >= 0; --j) {
            if (board[i][j] != 'X') {
                for (int k = 0; k < 3; ++k) {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if (x >= 0 && x < boardSize && y >= 0 && y < boardSize) {
                        dp[i][j] = fmax(dp[i][j], dp[x][y] + (board[i][j] - '0'));
                    }
                }
                if (dp[i][j] == maxSum) {
                    ++count;
                } else if (dp[i][j] > maxSum) {
                    maxSum = dp[i][j];
                    count = 1;
                }
            }
        }
    }

    int* ans = (int*)malloc(2 * sizeof(int));
    ans[0] = maxSum;
    ans[1] = count;
    *returnSize = 2;
    int mod = 1000000007;
    int* ans = (int*)malloc(2 * sizeof(int));
    ans[0] = maxSum % mod;
    ans[1] = count % mod;
    return ans;
}