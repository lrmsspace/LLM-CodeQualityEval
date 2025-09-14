#https://leetcode.com/problems/number-of-days-between-two-dates/
#Write a program to count the number of days between two dates.
#The two dates are given as strings, their format is YYYY-MM-DD as shown in the examples.
# 
#Example 1:
#Input: date1 = "2019-06-29", date2 = "2019-06-30"
#Output: 1
#Example 2:
#Input: date1 = "2020-01-15", date2 = "2019-12-31"
#Output: 15
# 
#Constraints:
#	The given dates are valid dates between the years 1971 and 2100.
class Solution(object):
    def daysBetweenDates(self, date1, date2):
        """
        :type date1: str
        :type date2: str
        :rtype: int
        """
        from datetime import datetime
        date_format = "%Y-%m-%d"
        d1 = datetime.strptime(date1, date_format)
        d2 = datetime.strptime(date2, date_format)
        return abs((d1 - d2).days)        