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
        if not nums or k <= 0:
            return []
        
        n = len(nums)
        result = []
        
        # Initialize deque to store indices of maximum values in the current window
        max_indices = collections.deque()
        
        # Iterate through the array from left to right
        for i in range(n):
            # Remove indices of elements that are out of the current window
            while max_indices and nums[max_indices[-1]] <= nums[i]:
                max_indices.pop()
            
            # Add the current index to the deque
            max_indices.append(i)
            
            # Add the maximum value of the current window to the result
            if i >= k - 1:
                result.append(nums[max_indices[0]])
        
        return result
        