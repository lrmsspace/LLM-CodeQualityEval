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
        n = len(arr)
        right_max = [0] * n
        right_max[-1] = arr[-1]
        for i in range(n - 2, -1, -1):
            right_max[i] = max(right_max[i + 1], arr[i])
        left_min = [0] * n
        left_min[0] = arr[0]
        for i in range(1, n):
            left_min[i] = min(left_min[i - 1], arr[i])
        ans = 0
        for i in range(n - 1):
            if left_min[i] <= right_max[i + 1]:
                ans += 1
        return ans + 1