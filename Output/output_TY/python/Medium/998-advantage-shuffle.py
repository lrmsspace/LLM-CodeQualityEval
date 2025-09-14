#https://leetcode.com/problems/advantage-shuffle/
#You are given two integer arrays nums1 and nums2 both of the same length. The advantage of nums1 with respect to nums2 is the number of indices i for which nums1[i] > nums2[i].
#Return any permutation of nums1 that maximizes its advantage with respect to nums2.
# 
#Example 1:
#Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
#Output: [2,11,7,15]
#Example 2:
#Input: nums1 = [12,24,8,32], nums2 = [13,25,32,11]
#Output: [24,32,8,12]
# 
#Constraints:
#	1 <= nums1.length <= 105
#	nums2.length == nums1.length
#	0 <= nums1[i], nums2[i] <= 109
class Solution(object):
    def advantageCount(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        nums1.sort()
        nums2.sort()
        ans = [0] * len(nums1)
        i = 0
        j = 0
        while i < len(nums1):
            if nums1[i] > nums2[j]:
                ans[j] = nums1[i]
                i += 1
                j += 1
            else:
                j += 1
        return ans