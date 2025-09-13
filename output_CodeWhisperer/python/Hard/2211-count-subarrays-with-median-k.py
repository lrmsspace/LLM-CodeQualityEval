#https://leetcode.com/problems/count-subarrays-with-median-k/
#You are given an array nums of size n consisting of distinct integers from 1 to n and a positive integer k.
#Return the number of non-empty subarrays in nums that have a median equal to k.
#Note:
#	The median of an array is the middle element after sorting the array in ascending order. If the array is of even length, the median is the left middle element.
#	
#		For example, the median of [2,3,1,4] is 2, and the median of [8,4,3,5,1] is 4.
#	
#	
#	A subarray is a contiguous part of an array.
# 
#Example 1:
#Input: nums = [3,2,1,4,5], k = 4
#Output: 3
#Explanation: The subarrays that have a median equal to 4 are: [4], [4,5] and [1,4,5].
#Example 2:
#Input: nums = [2,3,1], k = 3
#Output: 1
#Explanation: [3] is the only subarray that has a median equal to 3.
# 
#Constraints:
#	n == nums.length
#	1 <= n <= 105
#	1 <= nums[i], k <= n
#	The integers in nums are distinct.
class Solution(object):
    def countSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        k_index = nums.index(k)
        res = 1
        d = {0: 1}
        pre = [0] * (n + 1)
        for i in range(n):
            if nums[i] < k:
                pre[i + 1] = pre[i] - 1
            elif nums[i] > k:
                pre[i + 1] = pre[i] + 1
            else:
                pre[i + 1] = pre[i]
            res += d.get(pre[i + 1] - 1, 0) + d.get(pre[i + 1], 0)
            d[pre[i + 1]] = d.get(pre[i + 1], 0) + 1
        return res

        