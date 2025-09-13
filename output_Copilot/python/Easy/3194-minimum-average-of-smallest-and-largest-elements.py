# You have an array of floating point numbers averages which is initially empty. You are given an array nums of n integers where n is even.
# You repeat the following procedure n / 2 times:
# Remove the smallest element, minElement, and the largest element maxElement, from nums.
# Add (minElement + maxElement) / 2 to averages.
# Return the minimum element in averages.
# Example 1:
# Input: nums = [7,8,3,4,15,13,4,1]
# Output: 5.5
# Explanation:
# step
# nums
# averages
# 0
# [7,8,3,4,15,13,4,1]
# []
# 1
# [7,8,3,4,13,4]
# [8]
# 2
# [7,8,4,4]
# [8,8]
# 3
# [7,4]
# [8,8,6]
# 4
# []
# [8,8,6,5.5]
# The smallest element of averages, 5.5, is returned.
# Example 2:
# Input: nums = [1,9,8,3,10,5]
# Output: 5.5
# Explanation:
# step
# nums
# averages
# 0
# [1,9,8,3,10,5]
# []
# 1
# [9,8,3,5]
# [5.5]
# 2
# [8,5]
# [5.5,6]
# 3
# []
# [5.5,6,6.5]
# Example 3:
# Input: nums = [1,2,3,7,8,9]
# Output: 5.0
# Explanation:
# step
# nums
# averages
# 0
# [1,2,3,7,8,9]
# []
# 1
# [2,3,7,8]
# [5]
# 2
# [3,7]
# [5,5]
# 3
# []
# [5,5,5]
# Constraints:
# 2 <= n == nums.length <= 50
# n is even.
# 1 <= nums[i] <= 50

class Solution(object):
    def minimumAverage(self, nums):
        """
        :type nums: List[int]
        :rtype: float
        """
        nums.sort()
        averages = []
        n = len(nums)
        
        for i in range(n // 2):
            minElement = nums[i]
            maxElement = nums[n - 1 - i]
            averages.append((minElement + maxElement) / 2.0)
        
        return min(averages) if averages else 0.0
        