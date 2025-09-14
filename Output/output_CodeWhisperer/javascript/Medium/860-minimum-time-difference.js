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
    let minutes = [];
    for (let i = 0; i < timePoints.length; i++) {
        let time = timePoints[i].split(':');
        let hour = parseInt(time[0]);
        let minute = parseInt(time[1]);
        minutes.push(hour * 60 + minute);
    }
    minutes.sort((a, b) => a - b);
    let minDiff = minutes[0] + 1440 - minutes[minutes.length - 1];
    for (let i = 1; i < minutes.length; i++) {
        minDiff = Math.min(minDiff, minutes[i] - minutes[i - 1]);
    }
    return minDiff;
};