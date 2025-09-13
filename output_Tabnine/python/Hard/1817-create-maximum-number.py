#https://leetcode.com/problems/create-maximum-number/
#You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.
#Create the maximum number of length k <= m + n from digits of the two numbers. The relative order of the digits from the same array must be preserved.
#Return an array of the k digits representing the answer.
# 
#Example 1:
#Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
#Output: [9,8,6,5,3]
#Example 2:
#Input: nums1 = [6,7], nums2 = [6,0,4], k = 5
#Output: [6,7,6,0,4]
#Example 3:
#Input: nums1 = [3,9], nums2 = [8,9], k = 3
#Output: [9,8,9]
# 
#Constraints:
#	m == nums1.length
#	n == nums2.length
#	1 <= m, n <= 500
#	0 <= nums1[i], nums2[i] <= 9
#	1 <= k <= m + n
class Solution(object):
    def maxNumber(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[int]
        """
        def merge(nums1, nums2, k):
            n1, n2 = len(nums1), len(nums2)
            i, j, res = 0, 0, []
            while i < n1 and j < n2 and k > 0:
                if self.isGreater(nums1, i, nums2, j):
                    res.append(nums1[i])
                    i += 1
                else:
                    res.append(nums2[j])
                    j += 1
                k -= 1
            while i < n1 and k > 0:
                res.append(nums1[i])
                i += 1
                k -= 1
            while j < n2 and k > 0:
                res.append(nums2[j])
                j += 1
                k -= 1
            return res
        
        def isGreater(self, nums1, i, nums2, j):
            n1, n2 = len(nums1), len(nums2)
            while i < n1 and j < n2:
                if nums1[i] > nums2[j]:
                    return True
                elif nums1[i] < nums2[j]:
                    return False
                i += 1
                j += 1
            return i < n1
        
        return merge(nums1, nums2, k)
        