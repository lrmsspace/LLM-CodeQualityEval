#https://leetcode.com/problems/find-right-interval/
#You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.
#The right interval for an interval i is an interval j such that startj >= endi and startj is minimized. Note that i may equal j.
#Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.
# 
#Example 1:
#Input: intervals = [[1,2]]
#Output: [-1]
#Explanation: There is only one interval in the collection, so it outputs -1.
#Example 2:
#Input: intervals = [[3,4],[2,3],[1,2]]
#Output: [-1,0,1]
#Explanation: There is no right interval for [3,4].
#The right interval for [2,3] is [3,4] since start0 = 3 is the smallest start that is >= end1 = 3.
#The right interval for [1,2] is [2,3] since start1 = 2 is the smallest start that is >= end2 = 2.
#Example 3:
#Input: intervals = [[1,4],[2,3],[3,4]]
#Output: [-1,2,-1]
#Explanation: There is no right interval for [1,4] and [3,4].
#The right interval for [2,3] is [3,4] since start2 = 3 is the smallest start that is >= end1 = 3.
# 
#Constraints:
#	1 <= intervals.length <= 2 * 104
#	intervals[i].length == 2
#	-106 <= starti <= endi <= 106
#	The start point of each interval is unique.
class Solution(object):
    def findRightInterval(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[int]
        """
        # Build a map from end times to intervals
        end_to_intervals = {}
        for i, (start, end) in enumerate(intervals):
            end_to_intervals.setdefault(end, []).append(i)
        
        # Sort the end times in ascending order
        end_times = sorted(end_to_intervals.keys())
        
        result = []
        for start in intervals:
            # Find the smallest end time greater than or equal to the start time
            right_interval_end = bisect_left(end_times, start[1])
            
            # If no right interval exists, put -1
            if right_interval_end == len(end_times):
                result.append(-1)
            else:
                # Get the index of the interval with the smallest start time
                right_interval_start = end_times[right_interval_end]
                result.append(end_to_intervals[right_interval_start].pop(0) if end_to_intervals[right_interval_start] else -1)
        
        return result
        