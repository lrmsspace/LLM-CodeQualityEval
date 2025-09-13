#https://leetcode.com/problems/intersection-of-two-arrays/
#Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
# 
#Example 1:
#Input: nums1 = [1,2,2,1], nums2 = [2,2]
#Output: [2]
#Example 2:
#Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
#Output: [9,4]
#Explanation: [4,9] is also accepted.
# 
#Constraints:
#	1 <= nums1.length, nums2.length <= 1000
#	0 <= nums1[i], nums2[i] <= 1000
class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        # Create a set from nums1 for faster lookup
        nums1_set = set(nums1)
        
        # Initialize an empty list to store the intersection
        intersection = []
        
        # Iterate through nums2
        for num in nums2:
            # If the number is in nums1_set and not already in intersection, add it
            if num in nums1_set and num not in intersection:
                intersection.append(num)
        
        return intersection
        