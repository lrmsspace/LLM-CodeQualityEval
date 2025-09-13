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
        if not nums:
            return []
        
        from collections import deque
        q = deque()
        res = []
        for i, num in enumerate(nums):
            while q and q[-1] < num:
                q.pop()
            q.append(num)
            if i >= k and q[0] == nums[i - k]:
                q.popleft()
            if i >= k - 1:
                res.append(q[0])
        return res
