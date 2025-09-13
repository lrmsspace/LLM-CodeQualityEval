#https://leetcode.com/problems/partition-equal-subset-sum/
#Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
# 
#Example 1:
#Input: nums = [1,5,11,5]
#Output: true
#Explanation: The array can be partitioned as [1, 5, 5] and [11].
#Example 2:
#Input: nums = [1,2,3,5]
#Output: false
#Explanation: The array cannot be partitioned into equal sum subsets.
# 
#Constraints:
#	1 <= nums.length <= 200
#	1 <= nums[i] <= 100
class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        # Initialize the sum of the array
        total_sum = sum(nums)
        
        # If the sum is odd, it cannot be partitioned into two equal sums
        if total_sum % 2!= 0:
            return False
        
        # Create a boolean array to store the results of subsets of current sum
        dp = [False] * (total_sum // 2 + 1)
        
        # Set the first element to True
        dp[0] = True
        
        # Iterate through the array from the second element
        for num in nums:
            # Iterate through the possible sums
            for i in range(total_sum // 2, num - 1, -1):
                # If the current sum minus the current number equals a previous sum, then the current sum can be achieved
                dp[i] = dp[i] or dp[i - num]
        
        # Return whether the sum can be achieved
        return dp[total_sum // 2]
        