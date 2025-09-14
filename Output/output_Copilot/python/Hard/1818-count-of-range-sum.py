#https://leetcode.com/problems/count-of-range-sum/
#Given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower, upper] inclusive.
#Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j inclusive, where i <= j.
# 
#Example 1:
#Input: nums = [-2,5,-1], lower = -2, upper = 2
#Output: 3
#Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their respective sums are: -2, -1, 2.
#Example 2:
#Input: nums = [0], lower = 0, upper = 0
#Output: 1
# 
#Constraints:
#	1 <= nums.length <= 105
#	-231 <= nums[i] <= 231 - 1
#	-105 <= lower <= upper <= 105
#	The answer is guaranteed to fit in a 32-bit integer.
class Solution(object):
    def countRangeSum(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        # 计算前缀和
        prefix_sum = [0] * (len(nums) + 1)
        for i in range(len(nums)):
            prefix_sum[i + 1] = prefix_sum[i] + nums[i]

        # 归并排序 + 二分搜索
        def merge_sort(start, end):
            if start >= end:
                return 0

            mid = (start + end) // 2
            count = merge_sort(start, mid) + merge_sort(mid + 1, end)

            # 统计满足条件的范围和
            j = k = mid + 1
            for i in range(start, mid + 1):
                while j <= end and prefix_sum[j] - prefix_sum[i] < lower:
                    j += 1
                while k <= end and prefix_sum[k] - prefix_sum[i] <= upper:
                    k += 1
                count += k - j

            # 合并两个有序数组
            temp = []
            left, right = start, mid + 1
            while left <= mid and right <= end:
                if prefix_sum[left] <= prefix_sum[right]:
                    temp.append(prefix_sum[left])
                    left += 1
                else:
                    temp.append(prefix_sum[right])
                    right += 1
            while left <= mid:
                temp.append(prefix_sum[left])
                left += 1
            while right <= end:
                temp.append(prefix_sum[right])
                right += 1

            for i in range(len(temp)):
                prefix_sum[start + i] = temp[i]

            return count

        return merge_sort(0, len(nums))
#         return count