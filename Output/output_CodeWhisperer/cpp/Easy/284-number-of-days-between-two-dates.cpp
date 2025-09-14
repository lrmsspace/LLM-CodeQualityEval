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
        
        
        int year1 = stoi(date1.substr(0, 4));
        int month1 = stoi(date1.substr(5, 2));
        int day1 = stoi(date1.substr(8, 2));
        int year2 = stoi(date2.substr(0, 4));
        int month2 = stoi(date2.substr(5, 2));
        int day2 = stoi(date2.substr(8, 2));
        int days1 = day1 - 1;
        int days2 = day2 - 1;
        for (int i = 1; i < month1; i++) {
            if (i == 4 || i == 6 || i == 9 || i == 11) {
                days1 += 30;
            } else if (i == 2) {
                days1 += 28;
                if (year1 % 4 == 0 && (year1 % 100 != 0 || year1 % 400 == 0)) {
                    days1++;
                }
            } else {
                days1 += 31;
            }
        }
        for (int i = 1; i < month2; i++) {
            if (i == 4 || i == 6 || i == 9 || i == 11) {
                days2 += 30;
            } else if (i == 2) {
                days2 += 28;
                if (year2 % 4 == 0 && (year2 % 100 != 0 || year2 % 400 == 0)) {
                    days2++;
                }
            } else {
                days2 += 31;
            }
        }
        for (int i = year1; i < year2; i++) {
            days2 += 365;
            if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) {
                days2++;
            }
        }
        return abs(days2 - days1);
    }
};