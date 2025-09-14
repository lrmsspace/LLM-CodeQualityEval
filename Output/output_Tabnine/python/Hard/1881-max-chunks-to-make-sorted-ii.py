#https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
#You are given an integer array arr.
#We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.
#Return the largest number of chunks we can make to sort the array.
# 
#Example 1:
#Input: arr = [5,4,3,2,1]
#Output: 1
#Explanation:
#Splitting into two or more chunks will not return the required result.
#For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
#Example 2:
#Input: arr = [2,1,3,4,4]
#Output: 4
#Explanation:
#We can split into two chunks, such as [2, 1], [3, 4, 4].
#However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.
# 
#Constraints:
#	1 <= arr.length <= 2000
#	0 <= arr[i] <= 108
class Solution(object):
    def maxChunksToSorted(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        # Initialize two arrays to store the maximum value and minimum value seen so far
        max_val = [0] * len(arr)
        min_val = [float('inf')] * len(arr)
        
        # Traverse the array from left to right
        for i in range(len(arr)):
            # Update the maximum value seen so far
            max_val[i] = max(max_val[i-1], arr[i])
            
            # Update the minimum value seen so far
            min_val[i] = min(min_val[i-1], arr[i])
        
        # Count the number of chunks needed
        count = 0
        for i in range(len(arr)):
            if max_val[i] <= min_val[i+1]:
                count += 1
        
        return count
        