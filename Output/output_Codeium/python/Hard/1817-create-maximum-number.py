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
        def pickMax(nums, k, start, maxLen):
            maxDigit = 0
            maxIndex = start
            for i in range(start, min(start + maxLen, len(nums))):
                if nums[i] > maxDigit:
                    maxDigit = nums[i]
                    maxIndex = i
            return maxDigit, maxIndex
        
        ans = []
        i = j = 0
        while len(ans) < k:
            if i < len(nums1) and j < len(nums2):
                if nums1[i] > nums2[j]:
                    digit, i = pickMax(nums1, k - len(ans), i, len(nums1))
                else:
                    digit, j = pickMax(nums2, k - len(ans), j, len(nums2))
            elif i < len(nums1):
                digit, i = pickMax(nums1, k - len(ans), i, len(nums1))
            else:
                digit, j = pickMax(nums2, k - len(ans), j, len(nums2))
            ans.append(digit)
        return ans
