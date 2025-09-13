/**https://leetcode.com/problems/minimum-time-difference/ */
//Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
// 
//Example 1:
//Input: timePoints = ["23:59","00:00"]
//Output: 1
//Example 2:
//Input: timePoints = ["00:00","23:59","00:00"]
//Output: 0
// 
//Constraints:
//	2 <= timePoints.length <= 2 * 104
//	timePoints[i] is in the format "HH:MM".
/**
 * @param {string[]} timePoints
 * @return {number}
 */
var findMinDifference = function(timePoints) {
    const timeInMinutes = timePoints.map(time => {
        const [hours, minutes] = time.split(':').map(Number);
        return hours * 60 + minutes;
    });

    timeInMinutes.sort((a, b) => a - b);

    let minDiff = 1440 - (timeInMinutes[timeInMinutes.length - 1] - timeInMinutes[0]);

    for (let i = 1; i < timeInMinutes.length; i++) {
        minDiff = Math.min(minDiff, timeInMinutes[i] - timeInMinutes[i - 1]);
    }

    return minDiff;    
};