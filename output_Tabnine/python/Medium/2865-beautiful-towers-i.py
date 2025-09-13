# You are given an array heights of n integers representing the number of bricks in n consecutive towers. Your task is to remove some bricks to form a mountain-shaped tower arrangement. In this arrangement, the tower heights are non-decreasing, reaching a maximum peak value with one or multiple consecutive towers and then non-increasing.
# Return the maximum possible sum of heights of a mountain-shaped tower arrangement.
# Example 1:
# Input: heights = [5,3,4,1,1]
# Output: 13
# Explanation:
# We remove some bricks to make heights = [5,3,3,1,1], the peak is at index 0.
# Example 2:
# Input: heights = [6,5,3,9,2,7]
# Output: 22
# Explanation:
# We remove some bricks to make heights = [3,3,3,9,2,2], the peak is at index 3.
# Example 3:
# Input: heights = [3,2,5,5,2,3]
# Output: 18
# Explanation:
# We remove some bricks to make heights = [2,2,5,5,2,2], the peak is at index 2 or 3.
# Constraints:
# 1 <= n == heights.length <= 103
# 1 <= heights[i] <= 109

class Solution(object):
    def maximumSumOfHeights(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        n = len(heights)
        # Sort the heights in descending order
        heights.sort(reverse=True)
        
        # Initialize the prefix sum array
        prefix_sum = [0] * (n + 1)
        
        # Calculate the prefix sum
        for i in range(1, n + 1):
            prefix_sum[i] = prefix_sum[i - 1] + heights[i - 1]
        
        # Initialize the maximum sum
        max_sum = 0
        
        # Iterate through the heights and calculate the maximum sum
        for i in range(n):
            # Calculate the sum of removing the current height
            current_sum = prefix_sum[n] - prefix_sum[i + 1]
            
            # Calculate the height of the current tower
            current_height = heights[i]
            
            # Update the maximum sum if necessary
            max_sum = max(max_sum, current_sum + current_height)
        
        return max_sum
        