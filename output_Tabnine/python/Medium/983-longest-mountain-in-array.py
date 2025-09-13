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
        if len(arr) < 3:
            return 0
        
        peak = 0
        left = 0
        right = len(arr) - 1
        
        while peak < right:
            if arr[peak] < arr[peak+1]:
                peak += 1
            elif arr[peak] > arr[peak+1]:
                left = peak + 1
                while left < right and arr[left] < arr[left+1]:
                    left += 1
                while left < right and arr[right] <= arr[right-1]:
                    right -= 1
                peak = left
            else:
                peak += 1
        
        return right - left + 1
        