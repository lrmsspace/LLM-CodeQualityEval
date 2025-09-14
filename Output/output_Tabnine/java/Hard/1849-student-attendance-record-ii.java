/**https://leetcode.com/problems/student-attendance-record-ii/ */
//An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:
//	'A': Absent.
//	'L': Late.
//	'P': Present.
//Any student is eligible for an attendance award if they meet both of the following criteria:
//	The student was absent ('A') for strictly fewer than 2 days total.
//	The student was never late ('L') for 3 or more consecutive days.
//Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.
// 
//Example 1:
//Input: n = 2
//Output: 8
//Explanation: There are 8 records with length 2 that are eligible for an award:
//"PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
//Only "AA" is not eligible because there are 2 absences (there need to be fewer than 2).
//Example 2:
//Input: n = 1
//Output: 3
//Example 3:
//Input: n = 10101
//Output: 183236316
// 
//Constraints:
//	1 <= n <= 105
class Solution {
    public int checkRecord(int n) {
        int MOD = 1000000007;
        long[][] dp = new long[n + 1][3][3];
        dp[0][0][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    // Case 1: Keep the current status
                    dp[i][j][k] = (dp[i - 1][j][k] + dp[i - 1][j][(k + 1) % 3]) % MOD;
                    
                    // Case 2: Change 'L' to 'A'
                    if (j > 0) {
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][k]) % MOD;
                    }
                    
                    // Case 3: Change 'A' to 'L'
                    if (k > 0) {
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
                    }
                }
        
                // Case 4: Change 'A' to 'P'
                dp[i][j][2] = (dp[i][j][2] + dp[i - 1][j][(k + 1) % 3]) % MOD;
        
                // Case 5: Change 'P' to 'A'
                if (j > 0 && k > 0) {
                    dp[i][j][2] = (dp[i][j][2] + dp[i - 1][j - 1][k - 1]) % MOD;
                }
            }
        
            // Case 6: Change 'L' to 'P'
            if (j > 0) {
                dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j - 1][1]) % MOD;
            }
        }
        
        return (int) (dp[n][2][0] + dp[n][2][1] + dp[n][2][2]) % MOD;
    }
}