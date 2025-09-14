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
        int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month1 > 2 && (year1 % 4 == 0 && (year1 % 100 != 0 || year1 % 400 == 0))) ++days[2];
        if (month2 > 2 && (year2 % 4 == 0 && (year2 % 100 != 0 || year2 % 400 == 0))) ++days[2];
        int days1 = 0;
        for (int i = 0; i < month1; ++i) days1 += days[i];
        days1 += day1;
        int days2 = 0;
        for (int i = 0; i < month2; ++i) days2 += days[i];
        days2 += day2;
        int result = 0;
        while (days1 > days2) {
            ++result;
            if (month2 < 12) ++days2, ++month2;
            else ++days2, ++year2, month2 = 1;
        }
        while (days1 < days2) {
            ++result;
            if (month1 < 12) ++days1, ++month1;
            else ++days1, ++year1, month1 = 1;
        }
        return result;
    }
};