#https://leetcode.com/problems/contiguous-array/
#Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
# 
#Example 1:
#Input: nums = [0,1]
#Output: 2
#Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
#Example 2:
#Input: nums = [0,1,0]
#Output: 2
#Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
# 
#Constraints:
#	1 <= nums.length <= 105
#	nums[i] is either 0 or 1.
class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        d = {0: -1}
        res = 0
        count = 0
        for i in range(len(nums)):
            count += 2 * nums[i] - 1
            if count in d:
                res = max(res, i - d[count])
            else:
                d[count] = i
        return res