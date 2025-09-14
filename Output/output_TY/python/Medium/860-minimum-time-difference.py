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
        timePoints.append(timePoints[0])
        return min([(int(timePoints[i][0:2])*60+int(timePoints[i][3:5]))-(int(timePoints[i+1][0:2])*60+int(timePoints[i+1][3:5])) for i in range(len(timePoints)-1)])
    