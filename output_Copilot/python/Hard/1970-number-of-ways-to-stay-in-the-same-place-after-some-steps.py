#https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
#You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position to the right in the array, or stay in the same place (The pointer should not be placed outside the array at any time).
#Given two integers steps and arrLen, return the number of ways such that your pointer is still at index 0 after exactly steps steps. Since the answer may be too large, return it modulo 109 + 7.
# 
#Example 1:
#Input: steps = 3, arrLen = 2
#Output: 4
#Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
#Right, Left, Stay
#Stay, Right, Left
#Right, Stay, Left
#Stay, Stay, Stay
#Example 2:
#Input: steps = 2, arrLen = 4
#Output: 2
#Explanation: There are 2 differents ways to stay at index 0 after 2 steps
#Right, Left
#Stay, Stay
#Example 3:
#Input: steps = 4, arrLen = 2
#Output: 8
# 
#Constraints:
#	1 <= steps <= 500
#	1 <= arrLen <= 106
class Solution(object):
    def numWays(self, steps, arrLen):
        """
        :type steps: int
        :type arrLen: int
        :rtype: int
        """
        if steps == 0:
            return 1
        if arrLen == 1:
            return 1
        
        mod = 10**9 + 7
        max_pos = min(steps, arrLen - 1)
        
        dp = [[0] * (max_pos + 1) for _ in range(steps + 1)]
        dp[0][0] = 1
        
        for i in range(1, steps + 1):
            for j in range(max_pos + 1):
                dp[i][j] = dp[i - 1][j] % mod
                if j > 0:
                    dp[i][j] += dp[i - 1][j - 1] % mod
                if j < max_pos:
                    dp[i][j] += dp[i - 1][j + 1] % mod
        
        return dp[steps][0] % mod        