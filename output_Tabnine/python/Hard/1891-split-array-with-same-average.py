#https://leetcode.com/problems/split-array-with-same-average/
#You are given an integer array nums.
#You should move each element of nums into one of the two arrays A and B such that A and B are non-empty, and average(A) == average(B).
#Return true if it is possible to achieve that and false otherwise.
#Note that for an array arr, average(arr) is the sum of all the elements of arr over the length of arr.
# 
#Example 1:
#Input: nums = [1,2,3,4,5,6,7,8]
#Output: true
#Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have an average of 4.5.
#Example 2:
#Input: nums = [3,1]
#Output: false
# 
#Constraints:
#	1 <= nums.length <= 30
#	0 <= nums[i] <= 104
class Solution(object):
    def splitArraySameAverage(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        target_sum = sum(nums) // 2
        target_avg = target_sum / n
        
        if target_avg * n!= target_sum:
            return False
        
        target_sum_prefix = [0] * (n + 1)
        for i in range(1, n + 1):
            target_sum_prefix[i] = target_sum_prefix[i - 1] + nums[i - 1]
        
        dp = [[False] * (target_sum + 1) for _ in range(n + 1)]
        dp[0][0] = True
        
        for i in range(1, n + 1):
            for j in range(target_sum, -1, -1):
                if j >= nums[i - 1]:
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - nums[i - 1]]
        
        return dp[n][target_sum]
        