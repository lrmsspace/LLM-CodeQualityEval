#https://leetcode.com/problems/longest-turbulent-subarray/
#Given an integer array arr, return the length of a maximum size turbulent subarray of arr.
#A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.
#More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:
#	For i <= k < j:
#	
#		arr[k] > arr[k + 1] when k is odd, and
#		arr[k] < arr[k + 1] when k is even.
#	
#	
#	Or, for i <= k < j:
#	
#		arr[k] > arr[k + 1] when k is even, and
#		arr[k] < arr[k + 1] when k is odd.
#	
#	
# 
#Example 1:
#Input: arr = [9,4,2,10,7,8,8,1,9]
#Output: 5
#Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
#Example 2:
#Input: arr = [4,8,12,16]
#Output: 2
#Example 3:
#Input: arr = [100]
#Output: 1
# 
#Constraints:
#	1 <= arr.length <= 4 * 104
#	0 <= arr[i] <= 109
class Solution(object):
    def maxTurbulenceSize(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        if len(arr) == 1:
            return 1
        if len(arr) == 2:
            return 2 if arr[0] != arr[1] else 1
        res = 0
        i = 0
        while i < len(arr) - 1:
            if arr[i] == arr[i + 1]:
                i += 1
                continue
            j = i
            while j < len(arr) - 1 and (arr[j] < arr[j + 1] and arr[j] > arr[j - 1] or arr[j] > arr[j + 1] and arr[j] < arr[j - 1]):
                j += 1
            res = max(res, j - i + 1)
            i = j
        return res
        