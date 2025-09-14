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
        # Splitting the dates into year, month, and day
        year1, month1, day1 = map(int, date1.split('-'))
        year2, month2, day2 = map(int, date2.split('-'))
        
        # Calculating the total number of days between the two dates
        days = 0
        while year1!= year2 or month1!= month2 or day1!= day2:
            # Incrementing the day
            day1 += 1
            
            # If the day becomes 30, 31, or 28, increment the month and adjust the day accordingly
            if day1 > self.get_days_in_month(year1, month1):
                day1 = 1
                month1 += 1
                if month1 > 12:
                    month1 = 1
                    year1 += 1
        
        # Calculating the difference in days
        return (year2 - year1) * 365 + (month2 - month1) * 30 + day2 - day1
        