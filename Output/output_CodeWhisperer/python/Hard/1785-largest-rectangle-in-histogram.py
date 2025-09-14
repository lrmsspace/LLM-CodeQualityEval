#https://leetcode.com/problems/largest-rectangle-in-histogram/
#Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
# 
#Example 1:
#Input: heights = [2,1,5,6,2,3]
#Output: 10
#Explanation: The above is a histogram where width of each bar is 1.
#The largest rectangle is shown in the red area, which has an area = 10 units.
#Example 2:
#Input: heights = [2,4]
#Output: 4
# 
#Constraints:
#	1 <= heights.length <= 105
#	0 <= heights[i] <= 104
class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        stack = [-1]
        max_area = 0
        for i in range(len(heights)):
            while stack[-1] != -1 and heights[stack[-1]] >= heights[i]:
                max_area = max(max_area, heights[stack.pop()] * (i - stack[-1] - 1))
            stack.append(i)
        while stack[-1] != -1:
            max_area = max(max_area, heights[stack.pop()] * (len(heights) - stack[-1] - 1))
        return max_area
        