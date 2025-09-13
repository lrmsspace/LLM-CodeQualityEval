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
        String[] d1 = date1.split("-");
        String[] d2 = date2.split("-");
        int year1 = Integer.parseInt(d1[0]);
        int month1 = Integer.parseInt(d1[1]);
        int day1 = Integer.parseInt(d1[2]);
        int year2 = Integer.parseInt(d2[0]);
        int month2 = Integer.parseInt(d2[1]);
        int day2 = Integer.parseInt(d2[2]);

        java.util.Calendar cal1 = java.util.Calendar.getInstance();
        cal1.set(year1, month1 - 1, day1);
        java.util.Calendar cal2 = java.util.Calendar.getInstance();
        cal2.set(year2, month2 - 1, day2);

        long diffInMillis = Math.abs(cal2.getTimeInMillis() - cal1.getTimeInMillis());
        return (int) (diffInMillis / (1000 * 60 * 60 * 24));        
    }
}