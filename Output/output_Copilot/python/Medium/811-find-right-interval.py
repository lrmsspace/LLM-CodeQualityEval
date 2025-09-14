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
        # Create a list of tuples (start, index) for each interval
        starts = [(interval[0], i) for i, interval in enumerate(intervals)]
        # Sort the starts list based on the start times
        starts.sort()
        
        result = [-1] * len(intervals)
        
        for end, index in intervals:
            # Binary search to find the right interval
            left, right = 0, len(starts) - 1
            while left <= right:
                mid = (left + right) // 2
                if starts[mid][0] < end:
                    left = mid + 1
                else:
                    right = mid - 1
            if left < len(starts):
                result[index] = starts[left][1]
        
        return result        