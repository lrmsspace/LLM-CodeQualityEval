#https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
#Given an integer array nums and two integers left and right, return the number of contiguous non-empty subarrays such that the value of the maximum array element in that subarray is in the range [left, right].
#The test cases are generated so that the answer will fit in a 32-bit integer.
# 
#Example 1:
#Input: nums = [2,1,4,3], left = 2, right = 3
#Output: 3
#Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
#Example 2:
#Input: nums = [2,9,2,5,6], left = 2, right = 8
#Output: 7
# 
#Constraints:
#	1 <= nums.length <= 105
#	0 <= nums[i] <= 109
#	0 <= left <= right <= 109
class Solution(object):
    def numSubarrayBoundedMax(self, nums, left, right):
        """
        :type nums: List[int]
        :type left: int
        :type right: int
        :rtype: int
        """
        n = len(nums)
        left_index = [i for i in range(n) if nums[i] >= left]
        right_index = [i for i in range(n) if nums[i] > right]
        if not left_index or not right_index:
            return 0
        left_index.append(n)
        right_index.append(n)
        res = 0
        for i in range(len(left_index)-1):
            for j in range(i+1, len(right_index)):
                res += (left_index[i+1]-left_index[i])*(right_index[j]-right_index[j-1])
        return res        