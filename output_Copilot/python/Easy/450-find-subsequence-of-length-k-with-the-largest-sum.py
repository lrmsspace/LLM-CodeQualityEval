#https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/
#You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.
#Return any such subsequence as an integer array of length k.
#A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
# 
#Example 1:
#Input: nums = [2,1,3,3], k = 2
#Output: [3,3]
#Explanation:
#The subsequence has the largest sum of 3 + 3 = 6.
#Example 2:
#Input: nums = [-1,-2,3,4], k = 3
#Output: [-1,3,4]
#Explanation: 
#The subsequence has the largest sum of -1 + 3 + 4 = 6.
#Example 3:
#Input: nums = [3,4,3,3], k = 2
#Output: [3,4]
#Explanation:
#The subsequence has the largest sum of 3 + 4 = 7. 
#Another possible subsequence is [4, 3].
# 
#Constraints:
#	1 <= nums.length <= 1000
#	-105 <= nums[i] <= 105
#	1 <= k <= nums.length
class Solution(object):
    def maxSubsequence(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # Sort the nums array in descending order and get the first k elements
        sorted_nums = sorted(nums, reverse=True)[:k]
        
        # Create a set from the sorted elements for quick lookup
        sorted_set = set(sorted_nums)
        
        # Create the result list by filtering the original nums array
        result = [num for num in nums if num in sorted_set and sorted_set.remove(num) is None]
        
        return result[:k]        