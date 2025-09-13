#https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
#Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.
# 
#Example 1:
#Input: nums = [8,2,4,7], limit = 4
#Output: 2 
#Explanation: All subarrays are: 
#[8] with maximum absolute diff |8-8| = 0 <= 4.
#[8,2] with maximum absolute diff |8-2| = 6 > 4. 
#[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
#[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
#[2] with maximum absolute diff |2-2| = 0 <= 4.
#[2,4] with maximum absolute diff |2-4| = 2 <= 4.
#[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
#[4] with maximum absolute diff |4-4| = 0 <= 4.
#[4,7] with maximum absolute diff |4-7| = 3 <= 4.
#[7] with maximum absolute diff |7-7| = 0 <= 4. 
#Therefore, the size of the longest subarray is 2.
#Example 2:
#Input: nums = [10,1,2,4,7,2], limit = 5
#Output: 4 
#Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
#Example 3:
#Input: nums = [4,2,2,2,4,4,2,2], limit = 0
#Output: 3
# 
#Constraints:
#	1 <= nums.length <= 105
#	1 <= nums[i] <= 109
#	0 <= limit <= 109
class Solution(object):
    def longestSubarray(self, nums, limit):
        """
        :type nums: List[int]
        :type limit: int
        :rtype: int
        """
        left = 0
        right = 0
        max_len = 0
        min_heap = []
        max_heap = []
        while right < len(nums):
            while min_heap and nums[right] <= min_heap[0]:
                heapq.heappush(max_heap, -heapq.heappop(min_heap))
            while max_heap and nums[right] >= -max_heap[0]:
                heapq.heappush(min_heap, -heapq.heappop(max_heap))
            heapq.heappush(max_heap, -nums[right])
            heapq.heappush(min_heap, nums[right])
            while -min_heap[0] - max_heap[0] > limit:
                if nums[left] == -min_heap[0]:
                    heapq.heappop(min_heap)
                if nums[left] == max_heap[0]:
                    heapq.heappop(max_heap)
                left += 1
            max_len = max(max_len, right - left + 1)
            right += 1
        return max_len    