/*
 You are given a m x n 2D array board representing a chessboard, where board[i][j] represents the value of the cell (i, j).
 Rooks in the same row or column attack each other. You need to place three rooks on the chessboard such that the rooks do not attack each other.
 Return the maximum sum of the cell values on which the rooks are placed.
 Example 1:
 Input: board = [[-3,1,1,1],[-3,1,-3,1],[-3,2,1,1]]
 Output: 4
 Explanation:
 We can place the rooks in the cells (0, 2), (1, 3), and (2, 1) for a sum of 1 + 1 + 2 = 4.
 Example 2:
 Input: board = [[1,2,3],[4,5,6],[7,8,9]]
 Output: 15
 Explanation:
 We can place the rooks in the cells (0, 0), (1, 1), and (2, 2) for a sum of 1 + 5 + 9 = 15.
 Example 3:
 Input: board = [[1,1,1],[1,1,1],[1,1,1]]
 Output: 3
 Explanation:
 We can place the rooks in the cells (0, 2), (1, 1), and (2, 0) for a sum of 1 + 1 + 1 = 3.
 Constraints:
 3 <= m == board.length <= 100
 3 <= n == board[i].length <= 100
 -109 <= board[i][j] <= 109
*/

long long maximumValueSum(int** board, int boardSize, int* boardColSize) {
    int m = boardSize;
    int n = boardColSize[0];
    
    // Create a 2D array dp to store the maximum sum for each cell
    long long** dp = (long long**)malloc(m * sizeof(long long*));
    for (int i = 0; i < m; i++) {
        dp[i] = (long long*)malloc(n * sizeof(long long));
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
    // Create a 2D array visited to track the cells visited by the rooks    
    int** visited = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        visited[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
    
    // Place the first rook in the top-left cell
    dp[0][0] = board[0][0];
    visited[0][0] = 1;
    
    // Place the second rook in the bottom-right cell
    dp[m - 1][n - 1] = board[m - 1][n - 1];
    visited[m - 1][n - 1] = 1;
    
    // Place the third rook in the remaining cells
    for (int i = 1; i < m; i++) {
        if (visited[i - 1][0] == 0) {
            dp[i][0] = dp[i - 1][0] + board[i][0];
        }
    }
    for (int j = 1; j < n; j++) {
        if (visited[0][j - 1] == 0) {
            dp[0][j] = dp[0][j - 1] + board[0][j];
        }
        visited[0][j - 1] = 1;
        visited[m - 1][j - 1] = 1;  
        dp[m - 1][j] = dp[m - 1][j - 1] + board[m - 1][j];
        visited[m - 1][j] = 1;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (visited[i - 1][j] == 0 && visited[i][j - 1] == 0) {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + board[i][j];
                }
            }
        }
    }
    long long maxSum = dp[m - 1][n - 1];    
    // Free the allocated memory
    for (int i = 0; i < m; i++) {
        free(dp[i]);
        free(visited[i]);
    }
    free(dp);
    free(visited);
    
    return maxSum;
    
}