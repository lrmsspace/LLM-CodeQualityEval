# Given an array of integers nums and an integer k, return the number of subarrays of nums where the bitwise AND of the elements of the subarray equals k.
# Example 1:
# Input: nums = [1,1,1], k = 1
# Output: 6
# Explanation:
# All subarrays contain only 1's.
# Example 2:
# Input: nums = [1,1,2], k = 1
# Output: 3
# Explanation:
# Subarrays having an AND value of 1 are: [1,1,2], [1,1,2], [1,1,2].
# Example 3:
# Input: nums = [1,2,3], k = 2
# Output: 2
# Explanation:
# Subarrays having an AND value of 2 are: [1,2,3], [1,2,3].
# Constraints:
# 1 <= nums.length <= 105
# 0 <= nums[i], k <= 109

class Solution(object):
    def countSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        count = 0
        
        for i in range(n):
            curr_and = nums[i]
            if curr_and == k:
                count += 1
            for j in range(i+1, n):
                curr_and &= nums[j]
                if curr_and == k:
                    count += 1
                # 提前终止：如果 AND 后小于 k，后续不可能恢复成 k
                if curr_and < k:
                    break
        return count