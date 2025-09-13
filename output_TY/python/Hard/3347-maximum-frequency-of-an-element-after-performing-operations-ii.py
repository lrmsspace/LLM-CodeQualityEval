# You are given an integer array nums and two integers k and numOperations.
# You must perform an operation numOperations times on nums, where in each operation you:
# Select an index i that was not selected in any previous operations.
# Add an integer in the range [-k, k] to nums[i].
# Return the maximum possible frequency of any element in nums after performing the operations.
# Example 1:
# Input: nums = [1,4,5], k = 1, numOperations = 2
# Output: 2
# Explanation:
# We can achieve a maximum frequency of two by:
# Adding 0 to nums[1], after which nums becomes [1, 4, 5].
# Adding -1 to nums[2], after which nums becomes [1, 4, 4].
# Example 2:
# Input: nums = [5,11,20,20], k = 5, numOperations = 1
# Output: 2
# Explanation:
# We can achieve a maximum frequency of two by:
# Adding 0 to nums[1].
# Constraints:
# 1 <= nums.length <= 105
# 1 <= nums[i] <= 109
# 0 <= k <= 109
# 0 <= numOperations <= nums.length

class Solution(object):
    def maxFrequency(self, nums, k, numOperations):
        """
        :type nums: List[int]
        :type k: int
        :type numOperations: int
        :rtype: int
        """
        # 对数组进行排序
        nums.sort()
        
        # 滑动窗口的左指针
        left = 0
        
        # 记录窗口内元素的总和
        total = 0
        
        # 遍历数组作为右指针
        for right in range(len(nums)):
            total += nums[right]
            
            # 计算窗口内所有元素变为当前元素所需的操作次数
            # 操作次数 = 目标值总和 - 实际值总和
            # 目标值总和 = nums[right] * (right - left + 1)
            # 实际值总和 = total
            while nums[right] * (right - left + 1) - total > k:
                total -= nums[left]
                left += 1
        
        # 最大频率就是滑动窗口的最大长度
        return len(nums) - left
        