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
        String[] days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        int[] months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int totalDays = 0;
        for(int i=1971;i<year;i++){
            totalDays += 365;
            if(i%4==0 && (i%100!=0 || i%400==0)){
                totalDays++;
            }
        }
        for(int i=0;i<month-1;i++){
            totalDays += months[i];
        }
        if(month>2 && year%4==0 && (year%100!=0 || year%400==0)){
            totalDays++;
        }
        totalDays += day;
        return days[(totalDays+4)%7];     
    }
}