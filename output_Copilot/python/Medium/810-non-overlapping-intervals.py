#https://leetcode.com/problems/non-overlapping-intervals/
#Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
#Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.
# 
#Example 1:
#Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
#Output: 1
#Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
#Example 2:
#Input: intervals = [[1,2],[1,2],[1,2]]
#Output: 2
#Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
#Example 3:
#Input: intervals = [[1,2],[2,3]]
#Output: 0
#Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
# 
#Constraints:
#	1 <= intervals.length <= 105
#	intervals[i].length == 2
#	-5 * 104 <= starti < endi <= 5 * 104
class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        # Sort the intervals based on the end time
        intervals.sort(key=lambda x: x[1])
        
        # Initialize the count of non-overlapping intervals and the end time of the last added interval
        count = 0
        end_time = float('-inf')
        
        for interval in intervals:
            # If the start time of the current interval is greater than or equal to the end time of the last added interval,
            # it means they do not overlap, so we can add this interval to our count
            if interval[0] >= end_time:
                count += 1
                end_time = interval[1]
        
        # The number of intervals to remove is the total number of intervals minus the count of non-overlapping intervals
        return len(intervals) - count        