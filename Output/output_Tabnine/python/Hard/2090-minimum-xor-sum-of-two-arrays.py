#https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/
#You are given two integer arrays nums1 and nums2 of length n.
#The XOR sum of the two integer arrays is (nums1[0] XOR nums2[0]) + (nums1[1] XOR nums2[1]) + ... + (nums1[n - 1] XOR nums2[n - 1]) (0-indexed).
#	For example, the XOR sum of [1,2,3] and [3,2,1] is equal to (1 XOR 3) + (2 XOR 2) + (3 XOR 1) = 2 + 0 + 2 = 4.
#Rearrange the elements of nums2 such that the resulting XOR sum is minimized.
#Return the XOR sum after the rearrangement.
# 
#Example 1:
#Input: nums1 = [1,2], nums2 = [2,3]
#Output: 2
#Explanation: Rearrange nums2 so that it becomes [3,2].
#The XOR sum is (1 XOR 3) + (2 XOR 2) = 2 + 0 = 2.
#Example 2:
#Input: nums1 = [1,0,3], nums2 = [5,3,4]
#Output: 8
#Explanation: Rearrange nums2 so that it becomes [5,4,3]. 
#The XOR sum is (1 XOR 5) + (0 XOR 4) + (3 XOR 3) = 4 + 4 + 0 = 8.
# 
#Constraints:
#	n == nums1.length
#	n == nums2.length
#	1 <= n <= 14
#	0 <= nums1[i], nums2[i] <= 107
class Solution(object):
    def minimumXORSum(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        # Sort both arrays in ascending order
        nums1.sort()
        nums2.sort()
        
        # Initialize the result and the current XOR sum
        result = 0
        curr_xor_sum = 0
        
        # Iterate through the arrays simultaneously
        i, j = 0, 0
        while i < len(nums1) and j < len(nums2):
            # XOR the current elements and add it to the current XOR sum
            curr_xor_sum = nums1[i] ^ nums2[j]
            
            # If the current XOR sum is less than the result, update the result
            if curr_xor_sum < result:
                result = curr_xor_sum
            
            # Move the pointer for the smaller element to the next position
            if nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1
        
        # If there are remaining elements in nums1, add them to the current XOR sum
        while i < len(nums1):
            result += nums1[i]
            i += 1
        
        # If there are remaining elements in nums2, add them to the current XOR sum
        while j < len(nums2):
            result += nums2[j]
            j += 1
        
        return result
        