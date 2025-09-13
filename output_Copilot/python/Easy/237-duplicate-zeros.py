#https://leetcode.com/problems/duplicate-zeros/
#Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.
#Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.
# 
#Example 1:
#Input: arr = [1,0,2,3,0,4,5,0]
#Output: [1,0,0,2,3,0,0,4]
#Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
#Example 2:
#Input: arr = [1,2,3]
#Output: [1,2,3]
#Explanation: After calling your function, the input array is modified to: [1,2,3]
# 
#Constraints:
#	1 <= arr.length <= 104
#	0 <= arr[i] <= 9
class Solution(object):
    def duplicateZeros(self, arr):
        """
        :type arr: List[int]
        :rtype: None Do not return anything, modify arr in-place instead.
        """
        n = len(arr)
        zeros = arr.count(0)  
        new_length = n + zeros
        # Traverse the array from the end to the beginning
        # This way, we can overwrite the elements without losing any information
        for i in range(n - 1, -1, -1):
            if arr[i] == 0:
                new_length -= 1
                if new_length < n:
                    arr[new_length] = 0
                new_length -= 1
            if new_length < n:
                arr[new_length] = arr[i]
        return arr     