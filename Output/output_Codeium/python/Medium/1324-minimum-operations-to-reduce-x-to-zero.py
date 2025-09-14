#https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
#You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.
#Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.
# 
#Example 1:
#Input: nums = [1,1,4,2,3], x = 5
#Output: 2
#Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
#Example 2:
#Input: nums = [5,6,7,8,9], x = 4
#Output: -1
#Example 3:
#Input: nums = [3,2,20,1,1,3], x = 10
#Output: 5
#Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
# 
#Constraints:
#	1 <= nums.length <= 105
#	1 <= nums[i] <= 104
#	1 <= x <= 109
class Solution(object):
    def minOperations(self, nums, x):
        """
        :type nums: List[int]
        :type x: int
        :rtype: int
        """
        n = len(nums)
        l = 0
        r = n - 1
        left_sum = 0
        right_sum = sum(nums)
        res = -1
        while l <= r:
            if left_sum == right_sum == x:
                res = max(res, r - l + 1)
            if left_sum < x:
                left_sum += nums[l]
                l += 1
            if right_sum > x:
                right_sum -= nums[r]
                r -= 1
        return res
