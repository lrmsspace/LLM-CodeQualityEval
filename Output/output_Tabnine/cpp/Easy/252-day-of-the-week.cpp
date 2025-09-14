/**https://leetcode.com/problems/day-of-the-week/ */
//Given a date, return the corresponding day of the week for that date.
//The input is given as three integers representing the day, month and year respectively.
//Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.
// 
//Example 1:
//Input: day = 31, month = 8, year = 2019
//Output: "Saturday"
//Example 2:
//Input: day = 18, month = 7, year = 1999
//Output: "Sunday"
//Example 3:
//Input: day = 15, month = 8, year = 1993
//Output: "Sunday"
// 
//Constraints:
//	The given dates are valid dates between the years 1971 and 2100.
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {

        // Define the number of days in each month and whether it's a leap year
        const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        bool isLeapYear = (year % 4 == 0 && year % 100!= 0) || (year % 400 == 0);
        
        // Calculate the total number of days from the start of the year to the given date
        int totalDays = 0;
        for (int i = 1971; i < year; ++i) {
            if (i % 4 == 0 && i % 100!= 0) {
                totalDays += 366;
            } else {
                totalDays += 365;
            }
        }
        
        for (int i = 1; i < month; ++i) {
            totalDays += daysInMonth[i - 1];
            if (i == 2 && isLeapYear) {
                ++totalDays;
            }
        }
        
        totalDays += day;
        
        // Calculate the day of the week
        const char* daysOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        return daysOfWeek[(totalDays % 7)];
        
    }
};