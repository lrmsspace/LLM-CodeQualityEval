#https://leetcode.com/problems/median-of-two-sorted-arrays/
#Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
#The overall run time complexity should be O(log (m+n)).
# 
#Example 1:
#Input: nums1 = [1,3], nums2 = [2]
#Output: 2.00000
#Explanation: merged array = [1,2,3] and median is 2.
#Example 2:
#Input: nums1 = [1,2], nums2 = [3,4]
#Output: 2.50000
#Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
# 
#Constraints:
#	nums1.length == m
#	nums2.length == n
#	0 <= m <= 1000
#	0 <= n <= 1000
#	1 <= m + n <= 2000
#	-106 <= nums1[i], nums2[i] <= 106
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        m, n = len(nums1), len(nums2)
        if m > n:
            nums1, nums2, m, n = nums2, nums1, n, m
        
        left, right = 0, m
        while left <= right:
            partitionX = left + (right - left) // 2
            partitionY = (m + n + 1) // 2 - partitionX
            
            maxLeftX = float('-inf') if partitionX == 0 else nums1[partitionX - 1]
            minRightX = float('inf') if partitionX == m else nums1[partitionX]
            
            maxLeftY = float('-inf') if partitionY == 0 else nums2[partitionY - 1]
            minRightY = float('inf') if partitionY == n else nums2[partitionY]
            
            if maxLeftX <= minRightY and maxLeftY <= minRightX:
                if (m + n) % 2 == 0:
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2
                else:
                    return max(maxLeftX, maxLeftY)
        
        return -1.0  # This should never be reached
        