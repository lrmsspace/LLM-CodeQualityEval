#https://leetcode.com/problems/sliding-window-maximum/
#You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
#Return the max sliding window.
# 
#Example 1:
#Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
#Output: [3,3,5,5,6,7]
#Explanation: 
#Window position                Max
#---------------               -----
#[1  3  -1] -3  5  3  6  7       3
# 1 [3  -1  -3] 5  3  6  7       3
# 1  3 [-1  -3  5] 3  6  7       5
# 1  3  -1 [-3  5  3] 6  7       5
# 1  3  -1  -3 [5  3  6] 7       6
# 1  3  -1  -3  5 [3  6  7]      7
#Example 2:
#Input: nums = [1], k = 1
#Output: [1]
# 
#Constraints:
#	1 <= nums.length <= 105
#	-104 <= nums[i] <= 104
#	1 <= k <= nums.length
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        from collections import deque
        if not nums:
            return []
        if k == 1:
            return nums
        
        deq = deque()
        max_window = []

        for i in range(len(nums)):
            # Remove indices that are out of the current window
            if deq and deq[0] < i - k + 1:
                deq.popleft()

            # Remove elements from the deque that are less than the current element
            while deq and nums[deq[-1]] < nums[i]:
                deq.pop()

            # Add the current index to the deque
            deq.append(i)

            # The first k-1 windows are not complete, so we skip them
            if i >= k - 1:
                max_window.append(nums[deq[0]])

        return max_window        