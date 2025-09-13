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
        # Sort both arrays
        nums1.sort()
        nums2.sort()
        
        # Initialize result array
        result = []
        
        # Initialize two pointers for nums1 and nums2
        i, j = 0, 0
        
        # Iterate over nums2
        while i < len(nums2):
            # If nums1[i] is greater than nums2[j], add nums1[i] to result and increment i
            if nums1[i] > nums2[j]:
                result.append(nums1[i])
                i += 1
            # If nums1[i] is less than or equal to nums2[j], add nums2[j] to result and increment j
            else:
                result.append(nums2[j])
                j += 1
        
        # Append remaining elements of nums1 to result
        result.extend(nums1[i:])
        
        return result
        