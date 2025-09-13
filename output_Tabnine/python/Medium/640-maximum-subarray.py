#https://leetcode.com/problems/maximum-subarray/
#Given an integer array nums, find the subarray with the largest sum, and return its sum.
# 
#Example 1:
#Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
#Output: 6
#Explanation: The subarray [4,-1,2,1] has the largest sum 6.
#Example 2:
#Input: nums = [1]
#Output: 1
#Explanation: The subarray [1] has the largest sum 1.
#Example 3:
#Input: nums = [5,4,-1,7,8]
#Output: 23
#Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
# 
#Constraints:
#	1 <= nums.length <= 105
#	-104 <= nums[i] <= 104
# 
#Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def helper(left, right):
            if left == right:
                return nums[left]
            mid = (left + right) // 2
            left_sum = helper(left, mid)
            right_sum = helper(mid + 1, right)
            cross_sum = max(nums[mid], nums[mid+1:]) + max(0, helper(left, mid-1), helper(mid+2, right))
            return max(left_sum, right_sum, cross_sum)
        
        return helper(0, len(nums) - 1)
        