#https://leetcode.com/problems/merge-intervals/
#Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
# 
#Example 1:
#Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
#Output: [[1,6],[8,10],[15,18]]
#Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
#Example 2:
#Input: intervals = [[1,4],[4,5]]
#Output: [[1,5]]
#Explanation: Intervals [1,4] and [4,5] are considered overlapping.
# 
#Constraints:
#	1 <= intervals.length <= 104
#	intervals[i].length == 2
#	0 <= starti <= endi <= 104
class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        # Sort the intervals based on start time
        intervals.sort(key=lambda x: x[0])
        
        # Initialize an empty result list and the current interval
        result = []
        current_interval = intervals[0]
        
        # Iterate through the sorted intervals
        for interval in intervals[1:]:
            # If the current interval overlaps with the next interval, merge them
            if current_interval[1] >= interval[0]:
                current_interval[1] = max(current_interval[1], interval[1])
            else:
                # If the current interval doesn't overlap with the next interval, add it to the result list
                result.append(current_interval)
                # Update the current interval with the next interval
                current_interval = interval
        
        # Add the last interval to the result list
        result.append(current_interval)
        
        return result
        