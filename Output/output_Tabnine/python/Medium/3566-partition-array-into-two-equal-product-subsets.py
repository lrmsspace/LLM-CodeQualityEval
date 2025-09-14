# You are given an integer array nums containing distinct positive integers and an integer target.
# Determine if you can partition nums into two non-empty disjoint subsets, with each element belonging to exactly one subset, such that the product of the elements in each subset is equal to target.
# Return true if such a partition exists and false otherwise.
# A subset of an array is a selection of elements of the array.
# Example 1:
# Input: nums = [3,1,6,8,4], target = 24
# Output: true
# Explanation: The subsets [3, 8] and [1, 6, 4] each have a product of 24. Hence, the output is true.
# Example 2:
# Input: nums = [2,5,3,7], target = 15
# Output: false
# Explanation: There is no way to partition nums into two non-empty disjoint subsets such that both subsets have a product of 15. Hence, the output is false.
# Constraints:
# 3 <= nums.length <= 12
# 1 <= target <= 1015
# 1 <= nums[i] <= 100
# All elements of nums are distinct.

class Solution(object):
    def checkEqualPartitions(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        n = len(nums)
        
        # Calculate the sum of all elements in nums
        total_sum = sum(nums)
        
        # If the total sum is not divisible by target, return False
        if total_sum % target!= 0:
            return False
        
        # Calculate the required sum for each subset
        subset_sum = total_sum // target
        
        # Initialize a 2D dp array with dimensions (n+1) x (subset_sum+1)
        dp = [[False] * (subset_sum + 1) for _ in range(n + 1)]
        
        # Initialize the first row and column of dp array with True
        for i in range(n + 1):
            dp[i][0] = True
        
        # Fill the dp array using the given conditions
        for i in range(1, n + 1):
            for j in range(1, subset_sum + 1):
                if nums[i - 1] <= j:
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] or dp[i - 1][j]
                else:
                    dp[i][j] = dp[i - 1][j]
        # Return True if the last element of dp array is True, otherwise False
        return dp[n][subset_sum]
        