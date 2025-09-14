#https://leetcode.com/problems/pizza-with-3n-slices/
#There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:
#	You will pick any pizza slice.
#	Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
#	Your friend Bob will pick the next slice in the clockwise direction of your pick.
#	Repeat until there are no more slices of pizzas.
#Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.
# 
#Example 1:
#Input: slices = [1,2,3,4,5,6]
#Output: 10
#Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.
#Example 2:
#Input: slices = [8,9,8,6,1,1]
#Output: 16
#Explanation: Pick pizza slice of size 8 in each turn. If you pick slice with size 9 your partners will pick slices of size 8.
# 
#Constraints:
#	3 * n == slices.length
#	1 <= slices.length <= 500
#	1 <= slices[i] <= 1000
class Solution(object):
    def maxSizeSlices(self, slices):
        """
        :type slices: List[int]
        :rtype: int
        """
        n = len(slices)
        if n < 3:
            return sum(slices)
        
        MOD = 10**9 + 7
        dp = [[0]*n for _ in range(3)]
        dp[0][0] = slices[0]
        dp[1][0] = slices[1]
        dp[2][0] = slices[2]
        
        for i in range(3, n):
            dp[0][i] = max(dp[1][i-1], dp[2][i-1]) + slices[i]
            dp[1][i] = max(dp[0][i-1], dp[2][i-1]) + slices[i-1]
            dp[2][i] = max(dp[0][i-1], dp[1][i-1]) + slices[i-2]
        
        return max(dp[0][n-1], dp[1][n-1], dp[2][n-1]) % MOD
        