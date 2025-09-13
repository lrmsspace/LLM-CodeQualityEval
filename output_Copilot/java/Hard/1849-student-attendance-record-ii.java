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
        long mod = 1000000007;
        long[][] dp = new long[n + 1][3];
        dp[0][0] = 1; // no absences, no late days
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod; // present
                if (j < 2) {
                    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod; // absent
                }
                if (j > 0) {
                    dp[i + 1][0] = (dp[i + 1][0] + dp[i][j]) % mod; // late
                }
            }
        }
        long ans = 0;
        for (int j = 0; j < 3; j++) {
            ans = (ans + dp[n][j]) % mod;
        }
        return (int) ans;        
    }
}