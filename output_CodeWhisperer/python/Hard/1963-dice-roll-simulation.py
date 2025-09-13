#https://leetcode.com/problems/dice-roll-simulation/
#A die simulator generates a random number from 1 to 6 for each roll. You introduced a constraint to the generator such that it cannot roll the number i more than rollMax[i] (1-indexed) consecutive times.
#Given an array of integers rollMax and an integer n, return the number of distinct sequences that can be obtained with exact n rolls. Since the answer may be too large, return it modulo 109 + 7.
#Two sequences are considered different if at least one element differs from each other.
# 
#Example 1:
#Input: n = 2, rollMax = [1,1,2,2,2,3]
#Output: 34
#Explanation: There will be 2 rolls of die, if there are no constraints on the die, there are 6 * 6 = 36 possible combinations. In this case, looking at rollMax array, the numbers 1 and 2 appear at most once consecutively, therefore sequences (1,1) and (2,2) cannot occur, so the final answer is 36-2 = 34.
#Example 2:
#Input: n = 2, rollMax = [1,1,1,1,1,1]
#Output: 30
#Example 3:
#Input: n = 3, rollMax = [1,1,1,2,2,3]
#Output: 181
# 
#Constraints:
#	1 <= n <= 5000
#	rollMax.length == 6
#	1 <= rollMax[i] <= 15
class Solution(object):
    def dieSimulator(self, n, rollMax):
        """
        :type n: int
        :type rollMax: List[int]
        :rtype: int
        """
        dp = [[0] * 6 for _ in range(n)]
        dp[0] = [1] * 6
        for i in range(1, n):
            for j in range(6):
                for k in range(6):
                    if j == k:
                        continue
                    dp[i][j] += dp[i - 1][k]
                if i > rollMax[j]:
                    dp[i][j] -= dp[i - rollMax[j] - 1][j]
                dp[i][j] %= 1000000007
        return sum(dp[n - 1]) % 1000000007
        