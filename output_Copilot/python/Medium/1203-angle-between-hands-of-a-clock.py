#https://leetcode.com/problems/angle-between-hands-of-a-clock/
#Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.
#Answers within 10-5 of the actual value will be accepted as correct.
# 
#Example 1:
#Input: hour = 12, minutes = 30
#Output: 165
#Example 2:
#Input: hour = 3, minutes = 30
#Output: 75
#Example 3:
#Input: hour = 3, minutes = 15
#Output: 7.5
# 
#Constraints:
#	1 <= hour <= 12
#	0 <= minutes <= 59
class Solution(object):
    def angleClock(self, hour, minutes):
        """
        :type hour: int
        :type minutes: int
        :rtype: float
        """
        # 计算时针和分针的角度

        hour_angle = (hour % 12 + minutes / 60.0) * 30  
        minute_angle = minutes * 6
        # 计算两者之间的角度差
        # angle = abs(hour_angle - minute_angle)
        angle = abs(hour_angle - minute_angle)
        # 返回较小的角度
        return min(angle, 360 - angle)        