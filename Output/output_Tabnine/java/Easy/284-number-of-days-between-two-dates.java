/**https://leetcode.com/problems/number-of-days-between-two-dates/ */
//Write a program to count the number of days between two dates.
//The two dates are given as strings, their format is YYYY-MM-DD as shown in the examples.
// 
//Example 1:
//Input: date1 = "2019-06-29", date2 = "2019-06-30"
//Output: 1
//Example 2:
//Input: date1 = "2020-01-15", date2 = "2019-12-31"
//Output: 15
// 
//Constraints:
//	The given dates are valid dates between the years 1971 and 2100.
class Solution {
    public int daysBetweenDates(String date1, String date2) {
        // Split the dates into year, month, and day
        int[] d1 = parseDate(date1);
        int[] d2 = parseDate(date2);
        
        // Calculate the number of days between the two dates
        int days = 0;
        for (int year = d1[0]; year < d2[0]; year++) {
            days += isLeapYear(year)? 366 : 365;
        }
        
        for (int month = 1; month < d1[1]; month++) {
            days += getDaysInMonth(d1[0], month);
        }
        
        for (int day = d1[2]; day < d2[2]; day++) {
            days++;
        }
        
        for (int month = d2[1]; month < 12; month++) {
            days += getDaysInMonth(d2[0], month);
        }
        
        return days - d2[2] + d1[2];
        
    }
}