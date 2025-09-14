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
int checkRecord(int n) {
    const int MOD = 1000000007;
    long long dp[n + 1][3][3] = {};
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][1][0] + dp[i - 1][2][0]) % MOD;
        dp[i][0][1] = dp[i - 1][0][0];
        dp[i][0][2] = dp[i - 1][0][1];
        dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][2]) % MOD;
        dp[i][1][1] = dp[i - 1][1][0];
        dp[i][1][2] = dp[i - 1][1][1];
        dp[i][2][0] = dp[i - 1][1][2];
        dp[i][2][1] = (dp[i - 1][0][1] + dp[i - 1][1][1] + dp[i - 1][2][1]) % MOD;
        dp[i][2][2] = dp[i - 1][2][1];
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k]) % MOD;
            }
        }
    }
    return (int) (dp[n][0][0] + dp[n][1][0] + dp[n][2][0]) % MOD;

}