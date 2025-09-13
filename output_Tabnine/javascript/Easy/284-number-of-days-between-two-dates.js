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
/**
 * @param {string} date1
 * @param {string} date2
 * @return {number}
 */
var daysBetweenDates = function(date1, date2) {
    // Convert date strings to Date objects
    var d1 = new Date(date1);
    var d2 = new Date(date2);
    
    // Calculate the number of milliseconds between the two dates
    var diff = Math.abs(d2 - d1);
    
    // Convert milliseconds to days
    var days = Math.floor(diff / (1000 * 60 * 60 * 24));
    
    return days;
    
};