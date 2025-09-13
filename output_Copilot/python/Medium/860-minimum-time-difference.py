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
        timePoints.sort()
        min_diff = float('inf')
        for i in range(1, len(timePoints)):
            diff = self.time_diff(timePoints[i], timePoints[i - 1])
            min_diff = min(min_diff, diff)
        # 处理跨天的情况
        diff = self.time_diff(timePoints[0], timePoints[-1])
        min_diff = min(min_diff, diff)
        return min_diff        