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
int* pathsWithMaxScore(char** board, int boardSize, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    
    // Replace 'S' and 'E' with '0' for easier processing
    board[boardSize-1][boardSize-1] = '0';  // 'S' position
    board[0][0] = '0';  // 'E' position
    
    // Initialize dp arrays
    // dp[i][j][0] = maximum sum to reach position (i, j)
    // dp[i][j][1] = number of paths with that maximum sum
    int*** dp = (int***)malloc(boardSize * sizeof(int**));
    for (int i = 0; i < boardSize; i++) {
        dp[i] = (int**)malloc(boardSize * sizeof(int*));
        for (int j = 0; j < boardSize; j++) {
            dp[i][j] = (int*)malloc(2 * sizeof(int));
            dp[i][j][0] = -1;  // -1 means unreachable
            dp[i][j][1] = 0;
        }
    }
    
    // Base case: Starting point (bottom right)
    dp[boardSize-1][boardSize-1][0] = 0;
    dp[boardSize-1][boardSize-1][1] = 1;
    
    // Fill dp table from bottom right to top left
    for (int i = boardSize - 1; i >= 0; i--) {
        for (int j = boardSize - 1; j >= 0; j--) {
            // Skip if current position is an obstacle
            if (board[i][j] == 'X') {
                continue;
            }
            
            // Skip the starting point (already handled)
            if (i == boardSize - 1 && j == boardSize - 1) continue;
            
            // Get the value at current position
            int value = board[i][j] - '0';
            
            // Initialize with unreachable
            int maxSum = -1;
            int paths = 0;
            
            // Check the three possible previous positions
            
            // From right
            if (j + 1 < boardSize && dp[i][j+1][0] != -1) {
                maxSum = dp[i][j+1][0] + value;
                paths = dp[i][j+1][1];
            }
            
            // From bottom
            if (i + 1 < boardSize && dp[i+1][j][0] != -1) {
                if (dp[i+1][j][0] + value > maxSum) {
                    maxSum = dp[i+1][j][0] + value;
                    paths = dp[i+1][j][1];
                } else if (dp[i+1][j][0] + value == maxSum) {
                    paths = (paths + dp[i+1][j][1]) % MOD;
                }
            }
            
            // From bottom-right (diagonal)
            if (i + 1 < boardSize && j + 1 < boardSize && dp[i+1][j+1][0] != -1) {
                if (dp[i+1][j+1][0] + value > maxSum) {
                    maxSum = dp[i+1][j+1][0] + value;
                    paths = dp[i+1][j+1][1];
                } else if (dp[i+1][j+1][0] + value == maxSum) {
                    paths = (paths + dp[i+1][j+1][1]) % MOD;
                }
            }
            
            dp[i][j][0] = maxSum;
            dp[i][j][1] = paths;
        }
    }
    
    // Get the result from the top-left position (E)
    if (dp[0][0][0] == -1) {
        result[0] = 0;
        result[1] = 0;
    } else {
        result[0] = dp[0][0][0];
        result[1] = dp[0][0][1];
    }
    
    // Restore the original board
    board[boardSize-1][boardSize-1] = 'S';
    board[0][0] = 'E';
    
    // Free memory
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            free(dp[i][j]);
        }
        free(dp[i]);
    }
    free(dp);
    
    return result;
}
