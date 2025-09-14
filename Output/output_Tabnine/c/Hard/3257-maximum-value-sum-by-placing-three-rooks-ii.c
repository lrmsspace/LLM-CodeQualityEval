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
 3 <= m == board.length <= 500
 3 <= n == board[i].length <= 500
 -109 <= board[i][j] <= 109
*/

long long maximumValueSum(int** board, int boardSize, int* boardColSize) {
    int m = boardSize;
    int n = boardColSize[0];
    long long maxSum = INT_MIN;
    
    // Create a 3D array dp to store the maximum sum for each position
    long long** dp = (long long**)malloc(m * sizeof(long long*));
    for (int i = 0; i < m; i++) {
        dp[i] = (long long*)malloc(n * sizeof(long long));
        for (int j = 0; j < n; j++) {
            dp[i][j] = INT_MIN;
        }
    }
    
    // Initialize the dp array with the cell values
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = board[i][j];
        }
    }   
    // Place the first rook in the first cell   
    dp[0][0] = INT_MIN;
    
    // Place the second rook in the last cell of each row
    for (int i = 0; i < m; i++) {
        dp[i][n - 1] = INT_MIN;
    }
    
    // Place the third rook in the last cell of each column
    for (int j = 0; j < n; j++) {
        dp[m - 1][j] = INT_MIN;
    }   
    // Place the rooks in the remaining cells   
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + board[i][j];
        }
    }
    
    // Return the maximum sum of the cell values
    maxSum = max(dp[m - 1][n - 1], maxSum);
    
    // Free the dp array
    for (int i = 0; i < m; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return maxSum;  
    
}