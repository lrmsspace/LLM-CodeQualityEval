#https://leetcode.com/problems/longest-mountain-in-array/
#You may recall that an array arr is a mountain array if and only if:
#	arr.length >= 3
#	There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
#	
#		arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
#		arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
#	
#	
#Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.
# 
#Example 1:
#Input: arr = [2,1,4,7,3,2,5]
#Output: 5
#Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
#Example 2:
#Input: arr = [2,2,2]
#Output: 0
#Explanation: There is no mountain.
# 
#Constraints:
#	1 <= arr.length <= 104
#	0 <= arr[i] <= 104
# 
#Follow up:
#	Can you solve it using only one pass?
#	Can you solve it in O(1) space?
class Solution(object):
    def longestMountain(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        n = len(arr)
        if n < 3:
            return 0

        longest = 0
        left = 0

        while left + 1 < n:
            # Find the peak of the mountain
            while left + 1 < n and arr[left] >= arr[left + 1]:
                left += 1
            peak = left

            # Find the right side of the mountain
            while peak + 1 < n and arr[peak] < arr[peak + 1]:
                peak += 1

            # If we found a valid mountain, update the longest length
            if peak > left:
                longest = max(longest, peak - left + 1)

            # Move to the next potential mountain start point
            left = peak + 1

        return longest if longest >= 3 else 0        