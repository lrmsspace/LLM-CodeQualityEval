#https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
#You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
#We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
# 
#Example 1:
#Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
#Output: [20,24]
#Explanation: 
#List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
#List 2: [0, 9, 12, 20], 20 is in range [20,24].
#List 3: [5, 18, 22, 30], 22 is in range [20,24].
#Example 2:
#Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
#Output: [1,1]
# 
#Constraints:
#	nums.length == k
#	1 <= k <= 3500
#	1 <= nums[i].length <= 50
#	-105 <= nums[i][j] <= 105
#	nums[i] is sorted in non-decreasing order.
class Solution(object):
    def smallestRange(self, nums):
        """
        :type nums: List[List[int]]
        :rtype: List[int]
        """
        import heapq
        h = []
        for i in range(len(nums)):
            heapq.heappush(h, (nums[i][0], i, 0))
        ans = [h[0][0], h[-1][0]]
        while True:
            x = heapq.heappop(h)
            if x[2] == len(nums[x[1]]) - 1:
                break
            heapq.heappush(h, (nums[x[1]][x[2] + 1], x[1], x[2] + 1))
            if h[-1][0] - h[0][0] < ans[-1] - ans[0]:
                ans = [h[0][0], h[-1][0]]
        return ans