#https://leetcode.com/problems/day-of-the-year/
#Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.
# 
#Example 1:
#Input: date = "2019-01-09"
#Output: 9
#Explanation: Given date is the 9th day of the year in 2019.
#Example 2:
#Input: date = "2019-02-10"
#Output: 41
# 
#Constraints:
#	date.length == 10
#	date[4] == date[7] == '-', and all other date[i]'s are digits
#	date represents a calendar date between Jan 1st, 1900 and Dec 31th, 2019.
class Solution(object):
    def dayOfYear(self, date):
        """
        :type date: str
        :rtype: int
        """
        year=int(date[0:4])
        month=int(date[5:7])
        day=int(date[8:])
        if month==1: return day
        if month==2: return day+31
        if month==3: return day+59
        if month==4: return day+90
        if month==5: return day+120
        if month==6: return day+151
        if month==7: return day+181
        if month==8: return day+212
        if month==9: return day+243
        if month==10: return day+273
        