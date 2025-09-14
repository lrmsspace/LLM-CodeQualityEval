# You are given 2 integer arrays nums1 and nums2 of lengths n and m respectively. You are also given a positive integer k.
# A pair (i, j) is called good if nums1[i] is divisible by nums2[j] * k (0 <= i <= n - 1, 0 <= j <= m - 1).
# Return the total number of good pairs.
# Example 1:
# Input: nums1 = [1,3,4], nums2 = [1,3,4], k = 1
# Output: 5
# Explanation:
# The 5 good pairs are (0, 0), (1, 0), (1, 1), (2, 0), and (2, 2).
# Example 2:
# Input: nums1 = [1,2,4,12], nums2 = [2,4], k = 3
# Output: 2
# Explanation:
# The 2 good pairs are (3, 0) and (3, 1).
# Constraints:
# 1 <= n, m <= 105
# 1 <= nums1[i], nums2[j] <= 106
# 1 <= k <= 103

class Solution(object):
    def numberOfPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: int
        """
        count = 0
        nums1.sort()
        nums2.sort()
        
        i = 0
        j = 0
        
        while i < len(nums1) and j < len(nums2):
            if nums1[i] // nums2[j] * nums2[j] == nums1[i]:
                count += len(nums2) - j
                i += 1
            elif nums1[i] // nums2[j] < nums2[j]:
                i += 1
            else:
                j += 1
        
        return count
        