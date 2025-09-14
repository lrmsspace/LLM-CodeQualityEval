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
int daysBetweenDates(char* date1, char* date2) {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year1 = atoi(date1);
    int month1 = atoi(date1 + 5);
    int day1 = atoi(date1 + 8);
    int year2 = atoi(date2);
    int month2 = atoi(date2 + 5);
    int day2 = atoi(date2 + 8);
    int days1 = 0;
    int days2 = 0;
    for (int i = 1971; i < year1; i++) {
        days1 += 365;
        if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) {
            days1++;
        }
    }
    for (int i = 1971; i < year2; i++) {
        days2 += 365;
        if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) {
            days2++;
        }
    }
    for (int i = 0; i < month1 - 1; i++) {
        days1 += days[i];
    }
    for (int i = 0; i < month2 - 1; i++) {
        days2 += days[i];
    }
    days1 += day1;
    days2 += day2;
    if (month1 > 2 && year1 % 4 == 0 && (year1 % 100 != 0 || year1 % 400 == 0)) {
        days1++;
    }
    if (month2 > 2 && year2 % 4 == 0 && (year2 % 100 != 0 || year2 % 400 == 0)) {
        days2++;
    }
    return abs(days1 - days2);
    
}