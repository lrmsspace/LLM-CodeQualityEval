# You are given an integer array nums and a positive integer k. Return the sum of the maximum and minimum elements of all subarrays with at most k elements.
# Example 1:
# Input: nums = [1,2,3], k = 2
# Output: 20
# Explanation:
# The subarrays of nums with at most 2 elements are:
# Subarray
# Minimum
# Maximum
# Sum
# [1]
# 1
# 1
# 2
# [2]
# 2
# 2
# 4
# [3]
# 3
# 3
# 6
# [1, 2]
# 1
# 2
# 3
# [2, 3]
# 2
# 3
# 5
# Final Total
# 20
# The output would be 20.
# Example 2:
# Input: nums = [1,-3,1], k = 2
# Output: -6
# Explanation:
# The subarrays of nums with at most 2 elements are:
# Subarray
# Minimum
# Maximum
# Sum
# [1]
# 1
# 1
# 2
# [-3]
# -3
# -3
# -6
# [1]
# 1
# 1
# 2
# [1, -3]
# -3
# 1
# -2
# [-3, 1]
# -3
# 1
# -2
# Final Total
# -6
# The output would be -6.
# Constraints:
# 1 <= nums.length <= 80000
# 1 <= k <= nums.length
# -106 <= nums[i] <= 106

class Solution(object):
    def minMaxSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        from collections import deque
        
        n = len(nums)
        total_sum = 0
        
        # 首先添加每个元素本身作为子数组的结果
        for num in nums:
            total_sum += 2 * num
        
        # 对于长度从2到k的子数组
        for length in range(2, k+1):
            # 计算所有长度为length的子数组的最大值和最小值之和
            window_sum = self.slidingWindowMinMaxSum(nums, length)
            total_sum += window_sum
        
        return total_sum
    
    def slidingWindowMinMaxSum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        max_result = []
        min_result = []
        dq_max = deque()  # 存储索引，对应最大值队列
        dq_min = deque()  # 存储索引，对应最小值队列
        total = 0
        
        for i in range(len(nums)):
            # 处理最大值队列
            while dq_max and dq_max[0] < i - k + 1:
                dq_max.popleft()
            while dq_max and nums[dq_max[-1]] < nums[i]:
                dq_max.pop()
            dq_max.append(i)
            
            # 处理最小值队列
            while dq_min and dq_min[0] < i - k + 1:
                dq_min.popleft()
            while dq_min and nums[dq_min[-1]] > nums[i]:
                dq_min.pop()
            dq_min.append(i)
            
            # 当窗口形成时，记录结果
            if i >= k - 1:
                max_val = nums[dq_max[0]]
                min_val = nums[dq_min[0]]
                total += max_val + min_val
        
        return total