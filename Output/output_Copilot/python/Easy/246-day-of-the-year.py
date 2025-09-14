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
        year, month, day = map(int, date.split('-'))
        days_in_month = [31, 28 + (year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        return sum(days_in_month[:month - 1]) + day        