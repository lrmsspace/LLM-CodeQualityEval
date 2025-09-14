/**https://leetcode.com/problems/day-of-the-year/ */
//Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.
// 
//Example 1:
//Input: date = "2019-01-09"
//Output: 9
//Explanation: Given date is the 9th day of the year in 2019.
//Example 2:
//Input: date = "2019-02-10"
//Output: 41
// 
//Constraints:
//	date.length == 10
//	date[4] == date[7] == '-', and all other date[i]'s are digits
//	date represents a calendar date between Jan 1st, 1900 and Dec 31th, 2019.
class Solution {
    public int dayOfYear(String date) {
        String[] split = date.split("-");
        int year = Integer.parseInt(split[0]);
        int month = Integer.parseInt(split[1]);
        int day = Integer.parseInt(split[2]);
        int[] daysInMonth = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
        if (isLeapYear(year)) {
            daysInMonth[2]++;
        }
        for (int i = 1; i < month; i++) {
            day += daysInMonth[i];
        }
        return day;        
    }
}