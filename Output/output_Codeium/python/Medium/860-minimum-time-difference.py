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
        def timeToMinutes(time):
            hours, minutes = map(int, time.split(":"))
            return hours * 60 + minutes
        
        minutes = sorted(timeToMinutes(time) for time in timePoints)
        min_diff = float('inf')
        
        for i in range(1, len(minutes)):
            min_diff = min(min_diff, minutes[i] - minutes[i - 1])
        
        # Check the difference between the first and last time points across midnight
        min_diff = min(min_diff, 1440 - minutes[-1] + minutes[0])
        
        return min_diff

