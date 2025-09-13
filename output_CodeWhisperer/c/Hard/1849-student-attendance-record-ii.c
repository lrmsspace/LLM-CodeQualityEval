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
    int mod = 1000000007;
    int dp[2][3][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                dp[j][0][i] = (dp[j][0][i] + dp[j][k][i - 1]) % mod;
                if (j == 0) {
                    dp[j + 1][0][i] = (dp[j + 1][0][i] + dp[j][k][i - 1]) % mod;
                }
                if (k < 2) {
                    dp[j][k + 1][i] = (dp[j][k + 1][i] + dp[j][k][i - 1]) % mod;
                }
            }
        }
    }
    int res = 0;
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 3; k++) {
            res = (res + dp[j][k][n]) % mod;
        }
    }
    return res;
    
}