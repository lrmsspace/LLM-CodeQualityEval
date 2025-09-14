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
/**
 * @param {number} day
 * @param {number} month
 * @param {number} year
 * @return {string}
 */
var dayOfTheWeek = function(day, month, year) {
    const daysOfWeek = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
    const months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    
    // Check if the year is a leap year
    if ((year % 4 === 0 && year % 100!== 0) || year % 400 === 0) {
        months[1] = 29;
    }
    
    // Calculate the total number of days from the start of the year
    let totalDays = 0;
    for (let i = 0; i < month - 1; i++) {
        totalDays += months[i];
    }
    totalDays += day;
    
    // Add the number of days from the start of the year to the given day of the year
    totalDays += (year - 1971) * 365 + Math.floor((year - 1969) / 4) - Math.floor((year - 1901) / 100) + Math.floor((year - 1601) / 400);
    
    // Return the corresponding day of the week
    return daysOfWeek[totalDays % 7];
    
};