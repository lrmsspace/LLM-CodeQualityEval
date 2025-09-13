#https://leetcode.com/problems/binary-watch/
#A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.
#	For example, the below binary watch reads "4:51".
#Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order.
#The hour must not contain a leading zero.
#	For example, "01:00" is not valid. It should be "1:00".
#The minute must consist of two digits and may contain a leading zero.
#	For example, "10:2" is not valid. It should be "10:02".
# 
#Example 1:
#Input: turnedOn = 1
#Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
#Example 2:
#Input: turnedOn = 9
#Output: []
# 
#Constraints:
#	0 <= turnedOn <= 10
class Solution(object):
    def readBinaryWatch(self, turnedOn):
        """
        :type turnedOn: int
        :rtype: List[str]
        """
        # Binary watch has 10 LEDs (4 for hours and 6 for minutes)
        # Each LED represents a binary digit (0 or 1)
        # We need to find all combinations of LEDs that sum up to turnedOn
        # For the hours, we can have 4 choices (0-11)
        # For the minutes, we can have 6 choices (0-59)
        
        def dfs(hours, minutes, remaining):
            if remaining == 0:
                # Convert hours and minutes to string format
                hour_str = str(hours) if hours < 10 else str(hours)
                minute_str = str(minutes) if minutes < 10 else str(minutes)
                return [hour_str + ":" + minute_str]
            
            result = []
            # For hours, we have 4 choices
            for h in range(4):
                if h > hours:
                    break
                result.extend(dfs(hours + h, minutes, remaining - h))
        
        # Initialize result list
        result = []
        
        # For hours, we have 4 choices
        for h in range(4):
            result.extend(dfs(h, 0, turnedOn - h))
        
        return result
        