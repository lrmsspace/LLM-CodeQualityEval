#https://leetcode.com/problems/minimum-time-difference/
#Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
# 
#Example 1:
#Input: timePoints = ["23:59","00:00"]
#Output: 1
#Example 2:
#Input: timePoints = ["00:00","23:59","00:00"]
#Output: 0
# 
#Constraints:
#	2 <= timePoints.length <= 2 * 104
#	timePoints[i] is in the format "HH:MM".
class Solution(object):
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        # Convert all time points to minutes since midnight
        timePoints = [int(time[:2]) * 60 + int(time[3:]) for time in timePoints]
        
        # Sort the time points in ascending order
        timePoints.sort()
        
        # Find the minimum difference
        min_diff = min(timePoints[i + 1] - timePoints[i] for i in range(len(timePoints) - 1))
        
        # Handle the case where the last time point is the earliest
        min_diff = min(min_diff, 24 * 60 - timePoints[-1] + timePoints[0])
        
        return min_diff
        