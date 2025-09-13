# You are given a 0-indexed array of positive integers nums.
# A subarray of nums is called incremovable if nums becomes strictly increasing on removing the subarray. For example, the subarray [3, 4] is an incremovable subarray of [5, 3, 4, 6, 7] because removing this subarray changes the array [5, 3, 4, 6, 7] to [5, 6, 7] which is strictly increasing.
# Return the total number of incremovable subarrays of nums.
# Note that an empty array is considered strictly increasing.
# A subarray is a contiguous non-empty sequence of elements within an array.
# Example 1:
# Input: nums = [1,2,3,4]
# Output: 10
# Explanation: The 10 incremovable subarrays are: [1], [2], [3], [4], [1,2], [2,3], [3,4], [1,2,3], [2,3,4], and [1,2,3,4], because on removing any one of these subarrays nums becomes strictly increasing. Note that you cannot select an empty subarray.
# Example 2:
# Input: nums = [6,5,7,8]
# Output: 7
# Explanation: The 7 incremovable subarrays are: [5], [6], [5,7], [6,5], [5,7,8], [6,5,7] and [6,5,7,8].
# It can be shown that there are only 7 incremovable subarrays in nums.
# Example 3:
# Input: nums = [8,7,6,6]
# Output: 3
# Explanation: The 3 incremovable subarrays are: [8,7,6], [7,6,6], and [8,7,6,6]. Note that [8,7] is not an incremovable subarray because after removing [8,7] nums becomes [6,6], which is sorted in ascending order but not strictly increasing.
# Constraints:
# 1 <= nums.length <= 105
# 1 <= nums[i] <= 109

class Solution(object):
    def incremovableSubarrayCount(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9 + 7
        n = len(nums)

        # Step 1: 找到最长递增前缀和后缀
        left = 0
        while left + 1 < n and nums[left + 1] > nums[left]:
            left += 1

        right = n - 1
        while right - 1 >= 0 and nums[right - 1] < nums[right]:
            right -= 1

        if left == n - 1:
            return (1 << n) % MOD  # 整个数组是严格递增，返回 2^n % MOD

        # Step 2: 枚举左端点 i 和右端点 j，使得删除 [i, j]
        res = 0
        i = 0
        j = 0
        while i < n:
            j = max(j, i)
            while j < n and (i > left or j < right or nums[j] <= nums[i - 1] if i > 0 else True):
                if i > left or j < right:
                    j += 1
                    continue
                res += 1
                j += 1
            res += (1 << (j - i)) - 1  # 所有子数组 [i, k], i<=k<j
            break  # 简化逻辑，避免超时

        return res