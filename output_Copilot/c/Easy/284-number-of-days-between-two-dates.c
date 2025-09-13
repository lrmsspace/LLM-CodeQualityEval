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
    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year1, month1, day1, year2, month2, day2;
    int i, days1, days2, days;
    sscanf(date1, "%d-%d-%d", &year1, &month1, &day1);
    sscanf(date2, "%d-%d-%d", &year2, &month2, &day2);
    days1 = 0;
    for (i = 1971; i < year1; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
            days1 += 366;
        } else {
            days1 += 365;
        }
    }
    for (i = 1; i < month1; i++) {
        days1 += month[i];
    }
    if (month1 > 2 && ((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 == 0)) {
        days1++;
    }
    days1 += day1;
    days2 = 0;
    for (i = 1971; i < year2; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
            days2 += 366;
        } else {
            days2 += 365;
        }
    }
    for (i = 1; i < month2; i++) {
        days2 += month[i];
    }
    if (month2 > 2 && ((year2 % 4 == 0 && year2 % 100 != 0) || year2 % 400 == 0)) {
        days2++;
    }
    days2 += day2;
    days = days1 - days2;
    return days > 0 ? days : -days;    
}