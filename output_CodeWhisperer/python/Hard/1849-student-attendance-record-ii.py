#https://leetcode.com/problems/student-attendance-record-ii/
#An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:
#	'A': Absent.
#	'L': Late.
#	'P': Present.
#Any student is eligible for an attendance award if they meet both of the following criteria:
#	The student was absent ('A') for strictly fewer than 2 days total.
#	The student was never late ('L') for 3 or more consecutive days.
#Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.
# 
#Example 1:
#Input: n = 2
#Output: 8
#Explanation: There are 8 records with length 2 that are eligible for an award:
#"PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
#Only "AA" is not eligible because there are 2 absences (there need to be fewer than 2).
#Example 2:
#Input: n = 1
#Output: 3
#Example 3:
#Input: n = 10101
#Output: 183236316
# 
#Constraints:
#	1 <= n <= 105
class Solution(object):
    def checkRecord(self, n):
        """
        :type n: int
        :rtype: int
        """
        MOD = 10**9 + 7
        dp = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
        dp[0][0] = 1
        for i in range(n):
            new_dp = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
            for j in range(3):
                for k in range(3):
                    if j == 0:
                        new_dp[j][0] = (new_dp[j][0] + dp[j][k]) % MOD
                    else:
                        new_dp[j][0] = (new_dp[j][0] + dp[j][k] + dp[j-1][k]) % MOD
                    if k < 2:
                        new_dp[j][k+1] = (new_dp[j][k+1] + dp[j][k]) % MOD
            dp = new_dp
        return sum(dp[j][k] for j in range(3) for k in range(3)) % MOD