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
public:
    int daysBetweenDates(string date1, string date2) {
        // Convert the dates to year, month, and day
        int year1 = stoi(date1.substr(0, 4));
        int month1 = stoi(date1.substr(5, 2));
        int day1 = stoi(date1.substr(8, 2));
        
        int year2 = stoi(date2.substr(0, 4));
        int month2 = stoi(date2.substr(5, 2));
        int day2 = stoi(date2.substr(8, 2));
        
        // Calculate the number of days between the two dates
        int days = 0;
        while (year1!= year2 || month1!= month2 || day1!= day2) {
            // Increment the day
            day1++;
            
            // If the day becomes 30, increment the month and decrement the day if necessary
            if (day1 > 30) {
                day1 = 1;
                month1++;
                
                // If the month becomes 13, increment the year and decrement the month if necessary
                if (month1 > 12) {
                    month1 = 1;
                    year1++;
                }
            }
            
            // Count the number of leap years between the two years
            int leapYears = 0;
            for (int i = year1; i < year2; i++) {
                if (isLeapYear(i)) {
                    leapYears++;
                }
            }
            
            // Add the leap years to the total days
            days += leapYears * 366;
        }
        
        return days;
        
    }
};