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
    const int MOD = 1e9 + 7;
    long long dp[3][2][3] = {1};
    for (int i = 1; i <= n; ++i) {
        long long ndp[3][2][3] = {0};
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 3; ++l) {
                    if (j == 0) {
                        ndp[1][k][l] += dp[j][k][l];
                        ndp[2][k][l] += dp[j][k][l];
                    }
                    if (k == 0) {
                        ndp[j][1][l] += dp[j][k][l];
                        ndp[j][1][(l+1)%3] += dp[j][k][l];
                    }
                    if (l == 0) {
                        ndp[j][k][1] += dp[j][k][l];
                    }
                    ndp[j][k][l] %= MOD;
                }
            }
        }
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 3; ++l) {
                    dp[j][k][l] = ndp[j][k][l];
                }
            }
        }
    }
    long long res = 0;
    for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 2; ++k) {
            for (int l = 0; l < 3; ++l) {
                res += dp[j][k][l];
            }
        }
    }
    return res % MOD;
}