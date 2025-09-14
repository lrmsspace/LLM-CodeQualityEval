/**https://leetcode.com/problems/knight-probability-in-chessboard/ */
//On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).
//A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.
//Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.
//The knight continues moving until it has made exactly k moves or has moved off the chessboard.
//Return the probability that the knight remains on the board after it has stopped moving.
// 
//Example 1:
//Input: n = 3, k = 2, row = 0, column = 0
//Output: 0.06250
//Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
//From each of those positions, there are also two moves that will keep the knight on the board.
//The total probability the knight stays on the board is 0.0625.
//Example 2:
//Input: n = 1, k = 0, row = 0, column = 0
//Output: 1.00000
// 
//Constraints:
//	1 <= n <= 25
//	0 <= k <= 100
//	0 <= row, column <= n - 1
double knightProbability(int n, int k, int row, int column) {
    double dp[25][25][101] = {0};
    int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    dp[row][column][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                for (int j = 0; j < 8; j++) {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        dp[nx][ny][i] += dp[x][y][i - 1] / 8;
                    }
                }
            }
        }
    }
    double ans = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            ans += dp[x][y][k];
        }
    }
    return ans; 
}