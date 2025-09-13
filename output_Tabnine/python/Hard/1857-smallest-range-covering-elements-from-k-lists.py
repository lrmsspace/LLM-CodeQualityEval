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
        minHeap, maxHeap = [], []
        
        for i, lst in enumerate(nums):
            heapq.heappush(minHeap, (lst[0], i, 0))
            heapq.heappush(maxHeap, (-lst[-1], i, len(lst) - 1))
        
        ans = minHeap[0][0] - maxHeap[0][0]
        start, end = minHeap[0][1], maxHeap[0][1]
        left, right = minHeap[0][2], maxHeap[0][2]
        
        while minHeap and maxHeap:
            if minHeap[0][0] - maxHeap[0][0] < ans:
                ans = minHeap[0][0] - maxHeap[0][0]
                start, end = minHeap[0][1], maxHeap[0][1]
                left, right = minHeap[0][2], maxHeap[0][2]
            
            if left < len(nums[minHeap[0][1]]):
                val = nums[minHeap[0][1]][left]
                heapq.heappush(maxHeap, (-val, minHeap[0][1], left))
                left += 1
            else:
                heapq.heappop(minHeap)
            
            if right > 0:
                val = nums[maxHeap[0][1]][right - 1]
                heapq.heappush(minHeap, (val, maxHeap[0][1], right - 1))
            
            right -= 1
        
        return [nums[start][left], nums[end][right]]