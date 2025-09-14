#https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/
#You are given an integer array, nums, and an integer k. nums comprises of only 0's and 1's. In one move, you can choose two adjacent indices and swap their values.
#Return the minimum number of moves required so that nums has k consecutive 1's.
# 
#Example 1:
#Input: nums = [1,0,0,1,0,1], k = 2
#Output: 1
#Explanation: In 1 move, nums could be [1,0,0,0,1,1] and have 2 consecutive 1's.
#Example 2:
#Input: nums = [1,0,0,0,0,0,1,1], k = 3
#Output: 5
#Explanation: In 5 moves, the leftmost 1 can be shifted right until nums = [0,0,0,0,0,1,1,1].
#Example 3:
#Input: nums = [1,1,0,1], k = 2
#Output: 0
#Explanation: nums already has 2 consecutive 1's.
# 
#Constraints:
#	1 <= nums.length <= 105
#	nums[i] is 0 or 1.
#	1 <= k <= sum(nums)
class Solution(object):
    def minMoves(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if k == 1:
            return 0 if nums.count(1) == 1 else 1
        A = [i for i, v in enumerate(nums) if v == 1]
        res = float('inf')
        left = [0] * (len(A) + 1)
        for i in range(1, len(A) + 1):
            left[i] = left[i - 1] + A[i - 1]
        for i in range(len(A) - k + 1):
            mid = i + k // 2
            right = (k - 1) * A[mid] - (left[mid] - left[i])
            for j in range(A[mid], A[mid + k - 1] + 1):
                right += abs(j - A[mid + k // 2])
            res = min(res, right)
        return res - (k // 2) * (k - 1)
        