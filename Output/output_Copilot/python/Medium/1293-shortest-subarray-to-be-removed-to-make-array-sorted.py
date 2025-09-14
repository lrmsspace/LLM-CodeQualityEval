#https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
#Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.
#Return the length of the shortest subarray to remove.
#A subarray is a contiguous subsequence of the array.
# 
#Example 1:
#Input: arr = [1,2,3,10,4,2,3,5]
#Output: 3
#Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
#Another correct solution is to remove the subarray [3,10,4].
#Example 2:
#Input: arr = [5,4,3,2,1]
#Output: 4
#Explanation: Since the array is strictly decreasing, we can only keep a single element. Therefore we need to remove a subarray of length 4, either [5,4,3,2] or [4,3,2,1].
#Example 3:
#Input: arr = [1,2,3]
#Output: 0
#Explanation: The array is already non-decreasing. We do not need to remove any elements.
# 
#Constraints:
#	1 <= arr.length <= 105
#	0 <= arr[i] <= 109
class Solution(object):
    def findLengthOfShortestSubarray(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        n = len(arr)
        left = 0
        right = n - 1

        # Find the longest non-decreasing prefix
        while left < n - 1 and arr[left] <= arr[left + 1]:
            left += 1

        # If the entire array is non-decreasing, return 0
        if left == n - 1:
            return 0

        # Find the longest non-decreasing suffix
        while right > 0 and arr[right] >= arr[right - 1]:
            right -= 1

        # Initialize the minimum length to remove
        min_length = min(n - left - 1, right)

        # Try to merge the prefix and suffix
        i, j = left, right
        while i >= 0 and j < n:
            if arr[i] <= arr[j]:
                min_length = min(min_length, j - i - 1)
                j += 1
            else:
                i -= 1

        return min_length        