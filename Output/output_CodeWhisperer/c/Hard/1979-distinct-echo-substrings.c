/**https://leetcode.com/problems/distinct-echo-substrings/ */
//Return the number of distinct non-empty substrings of text that can be written as the concatenation of some string with itself (i.e. it can be written as a + a where a is some string).
// 
//Example 1:
//Input: text = "abcabcabc"
//Output: 3
//Explanation: The 3 substrings are "abcabc", "bcabca" and "cabcab".
//Example 2:
//Input: text = "leetcodeleetcode"
//Output: 2
//Explanation: The 2 substrings are "ee" and "leetcodeleetcode".
// 
//Constraints:
//	1 <= text.length <= 2000
//	text has only lowercase English letters.
int distinctEchoSubstrings(char* text) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    
    // Replace 'S' with '0' and 'E' with '0' for easier processing
    char originalStart = board[boardSize-1][boardSize-1];
    char originalEnd = board[0][0];
    board[boardSize-1][boardSize-1] = '0';
    board[0][0] = '0';
    
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
            if (j + 1 < boardSize && board[i][j+1] != 'X' && dp[i][j+1][0] != -1) {
                maxSum = dp[i][j+1][0] + value;
                paths = dp[i][j+1][1];
            }
            
            // From bottom
            if (i + 1 < boardSize && board[i+1][j] != 'X' && dp[i+1][j][0] != -1) {
                if (dp[i+1][j][0] + value > maxSum) {
                    maxSum = dp[i+1][j][0] + value;
                    paths = dp[i+1][j][1];
                } else if (dp[i+1][j][0] + value == maxSum) {
                    paths = (paths + dp[i+1][j][1]) % MOD;
                }
            }
            
            // From bottom-right (diagonal)
            if (i + 1 < boardSize && j + 1 < boardSize && board[i+1][j+1] != 'X' && dp[i+1][j+1][0] != -1) {
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
    board[boardSize-1][boardSize-1] = originalStart;
    board[0][0] = originalEnd;
    
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
