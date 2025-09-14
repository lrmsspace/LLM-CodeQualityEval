#https://leetcode.com/problems/burst-balloons/
#You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
#If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
#Return the maximum coins you can collect by bursting the balloons wisely.
# 
#Example 1:
#Input: nums = [3,1,5,8]
#Output: 167
#Explanation:
#nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
#coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
#Example 2:
#Input: nums = [1,5]
#Output: 10
# 
#Constraints:
#	n == nums.length
#	1 <= n <= 300
#	0 <= nums[i] <= 100
class Solution(object):
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 1. Add 1 to both ends of the array
        nums = [1] + nums + [1]
        n = len(nums)
        
        # 2. Initialize a 2D DP array
        dp = [[0] * n for _ in range(n)]
        
        # 3. Fill the DP table
        for length in range(2, n):   # length of the subarray
            for left in range(n - length):
                right = left + length
                for i in range(left + 1, right):
                    dp[left][right] = max(dp[left][right], dp[left][i] + dp[i][right] + nums[left] * nums[i] * nums[right])
        # 4. The answer is in dp[0][n-1]
        
        # 5. Return the result
        return dp[0][n - 1]     