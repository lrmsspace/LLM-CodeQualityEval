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
    public String dayOfTheWeek(int day, int month, int year) {
        // The first day of the week is Sunday (0)
        int[] daysOfMonth = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        
        // Check if the year is a leap year
        boolean isLeapYear = (year % 4 == 0 && year % 100!= 0) || year % 400 == 0;
        
        // Adjust the day count for leap years
        if (isLeapYear && month > 2) {
            daysOfMonth[month] += 1;
        }
        
        // Calculate the total day count from the start of the year
        int totalDays = day + daysOfMonth[month - 1] + (year - 1971) * 365;
        
        // Adjust for the leap years
        for (int i = 1971; i < year; i++) {
            if ((i % 4 == 0 && i % 100!= 0) || i % 400 == 0) {
                totalDays++;
            }
        }
        
        // Calculate the day of the week
        int dayOfWeek = totalDays % 7;
        
        // Return the corresponding day of the week
        return switch (dayOfWeek) {
            case 0 -> "Sunday";
            case 1 -> "Monday";
            case 2 -> "Tuesday";
            case 3 -> "Wednesday";
            case 4 -> "Thursday";
            case 5 -> "Friday";
            default -> "Saturday";
        };
        
    }
}