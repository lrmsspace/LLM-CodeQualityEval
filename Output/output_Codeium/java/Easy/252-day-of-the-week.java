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
        String[] weeks = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        int t = day;
        int m = month;
        int y = year;
        if (m < 3) {
            m += 12;
            y -= 1;
        }
        int q = t;
        int m_ = m + 1;
        int K = y % 100;
        int J = y / 100;
        int f = q + 13*(m_-2)/5 + K + K/4 + J/4 + 5*J;
        int index = f % 7;
        return weeks[index];
    }
}