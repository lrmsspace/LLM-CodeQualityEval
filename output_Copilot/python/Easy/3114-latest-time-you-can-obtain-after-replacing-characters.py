# You are given a string s representing a 12-hour format time where some of the digits (possibly none) are replaced with a "?".
# 12-hour times are formatted as "HH:MM", where HH is between 00 and 11, and MM is between 00 and 59. The earliest 12-hour time is 00:00, and the latest is 11:59.
# You have to replace all the "?" characters in s with digits such that the time we obtain by the resulting string is a valid 12-hour format time and is the latest possible.
# Return the resulting string.
# Example 1:
# Input: s = "1?:?4"
# Output: "11:54"
# Explanation: The latest 12-hour format time we can achieve by replacing "?" characters is "11:54".
# Example 2:
# Input: s = "0?:5?"
# Output: "09:59"
# Explanation: The latest 12-hour format time we can achieve by replacing "?" characters is "09:59".
# Constraints:
# s.length == 5
# s[2] is equal to the character ":".
# All characters except s[2] are digits or "?" characters.
# The input is generated such that there is at least one time between "00:00" and "11:59" that you can obtain after replacing the "?" characters.

class Solution(object):
    def findLatestTime(self, s):
        """
        :type s: str
        :rtype: str
        """
        # Split the input string into hours and minutes
        hours, minutes = s.split(':')
        
        # Replace '?' in hours
        if hours[0] == '?':
            if hours[1] == '?' or int(hours[1]) < 4:
                hours = '1' + (hours[1] if hours[1] != '?' else '1')
            else:
                hours = '0' + (hours[1] if hours[1] != '?' else '9')
        elif hours[1] == '?':
            if int(hours[0]) < 2:
                hours = hours[0] + '9'
            else:
                hours = hours[0] + '3'
        
        # Replace '?' in minutes
        if minutes[0] == '?':
            minutes = '5' + (minutes[1] if minutes[1] != '?' else '9')
        elif minutes[1] == '?':
            minutes = minutes[0] + '9'
        
        return f"{hours}:{minutes}"
        