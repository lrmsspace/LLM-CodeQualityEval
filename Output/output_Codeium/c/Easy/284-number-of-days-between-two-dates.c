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
    int year1, year2, month1, month2, day1, day2;
    sscanf(date1, "%d-%d-%d", &year1, &month1, &day1);
    sscanf(date2, "%d-%d-%d", &year2, &month2, &day2);
    struct tm t1 = { 0, 0, 0, day1, month1 - 1, year1 - 1900 };
    struct tm t2 = { 0, 0, 0, day2, month2 - 1, year2 - 1900 };
    time_t t1t = mktime(&t1);
    time_t t2t = mktime(&t2);
    return (int) difftime(t2t, t1t) / (60 * 60 * 24);
}