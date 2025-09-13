#https://leetcode.com/problems/largest-time-for-given-digits/
#Given an array arr of 4 digits, find the latest 24-hour time that can be made using each digit exactly once.
#24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59. The earliest 24-hour time is 00:00, and the latest is 23:59.
#Return the latest 24-hour time in "HH:MM" format. If no valid time can be made, return an empty string.
# 
#Example 1:
#Input: arr = [1,2,3,4]
#Output: "23:41"
#Explanation: The valid 24-hour times are "12:34", "12:43", "13:24", "13:42", "14:23", "14:32", "21:34", "21:43", "23:14", and "23:41". Of these times, "23:41" is the latest.
#Example 2:
#Input: arr = [5,5,5,5]
#Output: ""
#Explanation: There are no valid 24-hour times as "55:55" is not valid.
# 
#Constraints:
#	arr.length == 4
#	0 <= arr[i] <= 9
class Solution(object):
    def largestTimeFromDigits(self, arr):
        """
        :type arr: List[int]
        :rtype: str
        """
        def isValid(h, m):
            return 0 <= h < 24 and 0 <= m < 60
        
        max_time = ""
        for h1 in arr:
            for h2 in arr:
                if h1 == h2:
                    continue
                for m1 in arr:
                    for m2 in arr:
                        if m1 == m2 or (h1 == 2 and m1 > 3) or (h2 == 2 and m2 > 3):
                            continue
                        time = f"{h1}{h2}:{m1}{m2}"
                        if isValid(int(time[:2]), int(time[3:])) and time > max_time:
                            max_time = time
        
        return max_time
        